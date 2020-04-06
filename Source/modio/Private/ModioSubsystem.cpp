// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioSubsystem.h"
#include "ModioHWrapper.h"
#include "../ModioPublic.h"
#include "ModioSettings.h"
#include "ModioModule.h"
#include "ModioUE4Utility.h"
#include "Schemas/ModioResponse.h"
#include "Engine/Engine.h"
#include "Misc/Paths.h"
#include <sstream>
#include <iostream>

FModioListenerDelegate FModioSubsystem::ModioOnModDownloadDelegate;
FModioListenerDelegate FModioSubsystem::ModioOnModUploadDelegate;
FModioModEventArrayDelegate FModioSubsystem::ModioOnModEventDelegate;

class LStream : public std::stringbuf {
protected:
	int sync() {
		UE_LOG(LogTemp, Log, TEXT("%s"), *FString(str().c_str()));
		str("");
		return std::stringbuf::sync();
	}
};

LStream UE4Stream;

FModioSubsystem::FModioSubsystem() :
  bInitialized(false)
{
}

FModioSubsystem::~FModioSubsystem()
{
  check(!bInitialized);
}

FModioSubsystemPtr FModioSubsystem::Create( const FString& RootDirectory, bool bRootDirectoryIsInUserSettingsDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironment, bool bInstallOnModDownload, bool bRetrieveModsFromOtherGames, bool bEnablePolling )
{
  if( !RootDirectory.Len() )
  {
    UE_LOG( LogModio, Warning, TEXT( "No root directory defined for Modio, modio will be initialized on the game directory" ) );
  }

  if( GameId == 0 )
  {
    UE_LOG( LogModio, Warning, TEXT( "No GameId defined for Modio, modio not initialized" ) );
    return nullptr;
  }

  if( !ApiKey.Len() )
  {
    UE_LOG( LogModio, Warning, TEXT( "No ApiKey defined for Modio, modio not initialized" ) );
    return nullptr;
  }

  FString LocalRootDirectory = "";
  if( bRootDirectoryIsInUserSettingsDirectory )
  {
    FString UserSettingsDir = FPlatformProcess::UserSettingsDir();
    LocalRootDirectory = UserSettingsDir + RootDirectory;
  } else
  {
    FString ProjectDirectory = FPaths::ConvertRelativePathToFull( FPaths::ProjectDir() );
    LocalRootDirectory = ProjectDirectory + RootDirectory;
  }

  FModioSubsystemPtr Modio = MakeShared<FModioSubsystem, ESPMode::Fast>();
  Modio->Init( LocalRootDirectory, GameId, ApiKey, bIsLiveEnvironment, bInstallOnModDownload, bRetrieveModsFromOtherGames, bEnablePolling );

  return Modio;
}

void FModioSubsystem::AddMod(const FModioModCreator& ModCreator, FModioModDelegate AddModDelegate)
{
  FModioAsyncRequest_AddMod *Request = new FModioAsyncRequest_AddMod( this, AddModDelegate );
  ModioModCreator mod_creator;
  modioInitModCreator(&mod_creator);
  SetupModioModCreator(ModCreator, mod_creator);
  modioAddMod(Request, mod_creator, FModioAsyncRequest_AddMod::Response);
  modioFreeModCreator(&mod_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::EditMod(uint32 ModId, const FModioModEditor &ModEditor, FModioModDelegate EditModDelegate)
{
  FModioAsyncRequest_EditMod *Request = new FModioAsyncRequest_EditMod( this, EditModDelegate );
  ModioModEditor mod_editor;
  modioInitModEditor(&mod_editor);
  SetupModioModEditor(ModEditor, mod_editor);
  modioEditMod(Request , (u32)ModId, mod_editor, FModioAsyncRequest_EditMod::Response);
  modioFreeModEditor(&mod_editor);
  QueueAsyncTask( Request );
}

void FModioSubsystem::EmailExchange( const FString &SecurityCode, FModioGenericDelegate EmailExchangeDelegate )
{
  FModioAsyncRequest_EmailExchange *Request = new FModioAsyncRequest_EmailExchange( this, EmailExchangeDelegate );
  modioEmailExchange( Request, TCHAR_TO_UTF8(*SecurityCode), FModioAsyncRequest_EmailExchange::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::EmailRequest( const FString &Email, FModioGenericDelegate EmailRequestDelegate )
{
  FModioAsyncRequest_EmailRequest *Request = new FModioAsyncRequest_EmailRequest( this, EmailRequestDelegate );
  modioEmailRequest( Request, TCHAR_TO_UTF8(*Email), FModioAsyncRequest_EmailRequest::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetAllMods(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, FModioModArrayDelegate GetAllModsDelegate)
{
  FModioAsyncRequest_GetAllMods *Request = new FModioAsyncRequest_GetAllMods( this, GetAllModsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioModFilterCreator(FilterCreator, ModTags, Limit, Offset, modio_filter_creator);
  modioGetAllMods(Request, modio_filter_creator, FModioAsyncRequest_GetAllMods::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetMod(uint32 ModId, const FModioModDelegate ModDelegate)
{
	FModioAsyncRequest_GetMod *Request = new FModioAsyncRequest_GetMod( this, ModDelegate );
	modioGetMod(Request, (u32)ModId, FModioAsyncRequest_GetMod::Response);
	QueueAsyncTask( Request );
}

void FModioSubsystem::GetAuthenticatedUser(FModioUserDelegate GetAuthenticatedUserDelegate)
{
  FModioAsyncRequest_GetAuthenticatedUser *Request = new FModioAsyncRequest_GetAuthenticatedUser( this, GetAuthenticatedUserDelegate );
  modioGetAuthenticatedUser(Request, FModioAsyncRequest_GetAuthenticatedUser::Response);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetUserEvents(int32 Limit, int32 Offset, FModioUserEventArrayDelegate GetUserEventsDelegate)
{
  FModioAsyncRequest_GetUserEvents *Request = new FModioAsyncRequest_GetUserEvents( this, GetUserEventsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioFilterPagination(Limit, Offset, modio_filter_creator);
  modioGetUserEvents(Request, modio_filter_creator, FModioAsyncRequest_GetUserEvents::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetUserRatings(int32 Limit, int32 Offset, FModioRatingArrayDelegate GetUserRatingsDelegate)
{
  FModioAsyncRequest_GetUserRatings *Request = new FModioAsyncRequest_GetUserRatings( this, GetUserRatingsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioFilterPagination(Limit, Offset, modio_filter_creator);
  modioGetUserRatings(Request, modio_filter_creator, FModioAsyncRequest_GetUserRatings::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetUserSubscriptions(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, FModioModArrayDelegate GetUserSubscriptionsDelegate)
{
  FModioAsyncRequest_GetUserSubscriptions *Request = new FModioAsyncRequest_GetUserSubscriptions( this, GetUserSubscriptionsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioModFilterCreator(FilterCreator, ModTags, Limit, Offset, modio_filter_creator);
  modioGetUserSubscriptions(Request, modio_filter_creator, FModioAsyncRequest_GetUserSubscriptions::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetUserMods(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, FModioModArrayDelegate GetUserModsDelegate)
{
  FModioAsyncRequest_GetUserMods *Request = new FModioAsyncRequest_GetUserMods( this, GetUserModsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioModFilterCreator(FilterCreator, ModTags, Limit, Offset, modio_filter_creator);
  modioGetUserMods(Request, modio_filter_creator, FModioAsyncRequest_GetUserMods::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetUserModfiles(int32 Limit, int32 Offset, FModioModfileArrayDelegate GetUserModfilesDelegate)
{
  FModioAsyncRequest_GetUserModfiles *Request = new FModioAsyncRequest_GetUserModfiles( this, GetUserModfilesDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioFilterPagination(Limit, Offset, modio_filter_creator);
  modioGetUserModfiles(Request, modio_filter_creator, FModioAsyncRequest_GetUserModfiles::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::SteamAuth(const FString &Base64Ticket, FModioGenericDelegate SteamAuthDelegate)
{
  FModioAsyncRequest_SteamAuth *Request = new FModioAsyncRequest_SteamAuth( this, SteamAuthDelegate );
  modioSteamAuthEncoded( Request, TCHAR_TO_UTF8(*Base64Ticket), FModioAsyncRequest_SteamAuth::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::GalaxyAuth(const FString &Appdata, FModioGenericDelegate GalaxyAuthDelegate)
{
  FModioAsyncRequest_GalaxyAuth *Request = new FModioAsyncRequest_GalaxyAuth( this, GalaxyAuthDelegate );
  modioGalaxyAuth( Request, TCHAR_TO_UTF8(*Appdata), FModioAsyncRequest_GalaxyAuth::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::OculusAuth(const FString& Nonce, const FString& OculusUserId, const FString& AccessToken, const FString& Email, const FString& Device, int32 DateExpires, FModioGenericDelegate OculusAuthDelegate)
{
  FModioAsyncRequest_OculusAuth *Request = new FModioAsyncRequest_OculusAuth( this, OculusAuthDelegate );
  modioOculusAuth( Request, TCHAR_TO_UTF8(*Nonce), TCHAR_TO_UTF8(*OculusUserId), TCHAR_TO_UTF8(*AccessToken), TCHAR_TO_UTF8(*Email), TCHAR_TO_UTF8(*Device), (u32)DateExpires, FModioAsyncRequest_GalaxyAuth::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::Process()
{
  modioProcess();
}

void FModioSubsystem::PollEvents()
{
  modioPollEvents();
}

void FModioSubsystem::SetModEventsPollInterval(int32 IntervalInSeconds)
{
  modioSetModEventsPollInterval((u32)IntervalInSeconds);
}

void FModioSubsystem::SetUserEventsPollInterval(int32 IntervalInSeconds)
{
  modioSetUserEventsPollInterval((u32)IntervalInSeconds);
}

void FModioSubsystem::Logout()
{
  modioLogout();
}

bool FModioSubsystem::IsLoggedIn()
{
  return modioIsLoggedIn();
}

FModioUser FModioSubsystem::CurrentUser()
{
  FModioUser User;
  InitializeUser(User, modioGetCurrentUser());
  return User;
}

void FModioSubsystem::AuthenticateViaToken(const FString& AccessToken)
{
  modioAuthenticateViaToken(TCHAR_TO_UTF8(*AccessToken));
}

void FModioSubsystem::DownloadMod(int32 ModId)
{
  modioDownloadMod((u32)ModId);
}

void FModioSubsystem::PauseDownloads()
{
  modioPauseDownloads();
}

void FModioSubsystem::ResumeDownloads()
{
  modioResumeDownloads();
}

FModioInstalledMod FModioSubsystem::GetInstalledMod(int32 ModId)
{
  FModioInstalledMod InstalledMod;

  ModioInstalledMod modio_installed_mod;
  modioGetInstalledMod((u32)ModId, &modio_installed_mod);

  InitializeInstalledMod(InstalledMod, modio_installed_mod);
  modioFreeInstalledMod(&modio_installed_mod);

  return InstalledMod;
}

TArray<FModioInstalledMod> FModioSubsystem::GetAllInstalledMods()
{
  TArray<FModioInstalledMod> InstalledMods;

  u32 installed_mods_count = modioGetAllInstalledModsCount();
  ModioInstalledMod *modio_installed_mods = (ModioInstalledMod *)malloc(installed_mods_count * sizeof(*modio_installed_mods));
  modioGetAllInstalledMods(modio_installed_mods);

  for (u32 i = 0; i < installed_mods_count; i++)
  {
    FModioInstalledMod installed_mod;
    InitializeInstalledMod(installed_mod, modio_installed_mods[i]);
    modioFreeInstalledMod(&modio_installed_mods[i]);
    InstalledMods.Add(installed_mod);
  }

  free(modio_installed_mods);

  return InstalledMods;
}

TArray<int32> FModioSubsystem::GetAllDownloadedMods()
{
  TArray<int32> DownloadedMods;

  u32 downloaded_mods_count = modioGetAllDownloadedModsCount();
  u32 *modio_downloaded_mods = new u32[downloaded_mods_count];
  modioGetAllDownloadedMods(modio_downloaded_mods);

  for (u32 i = 0; i < downloaded_mods_count; i++)
  {
    DownloadedMods.Add(modio_downloaded_mods[i]);
  }

  delete[] modio_downloaded_mods;

  return DownloadedMods;
}

TArray<FModioQueuedModDownload> FModioSubsystem::GetModDownloadQueue()
{
  TArray<FModioQueuedModDownload> QueuedMods;

  u32 download_queue_count = modioGetModDownloadQueueCount();
  ModioQueuedModDownload *modio_queued_mods = (ModioQueuedModDownload *)malloc(download_queue_count * sizeof(*modio_queued_mods));
  modioGetModDownloadQueue(modio_queued_mods);

  for (u32 i = 0; i < download_queue_count; i++)
  {
    FModioQueuedModDownload queued_mod;
    InitializeQueuedModDownload(queued_mod, modio_queued_mods[i]);
    modioFreeQueuedModDownload(&modio_queued_mods[i]);
    QueuedMods.Add(queued_mod);
  }

  free(modio_queued_mods);

  return QueuedMods;
}
void FModioSubsystem::InstallDownloadedMods()
{
  modioInstallDownloadedMods();
}
void FModioSubsystem::AddModfile(int32 ModId, FModioModfileCreator ModfileCreator)
{
  ModioModfileCreator modio_modfile_creator;
  modioInitModfileCreator(&modio_modfile_creator);
  SetupModioModfileCreator(ModfileCreator, modio_modfile_creator);
  modioAddModfile((u32)ModId, modio_modfile_creator);
  modioFreeModfileCreator(&modio_modfile_creator);
}
TArray<FModioQueuedModfileUpload> FModioSubsystem::GetModfileUploadQueue()
{
  TArray<FModioQueuedModfileUpload> UploadQueue;

  u32 upload_queue_count = modioGetModfileUploadQueueCount();
  ModioQueuedModfileUpload *modio_queued_mods = (ModioQueuedModfileUpload *)malloc(upload_queue_count * sizeof(*modio_queued_mods));
  modioGetModfileUploadQueue(modio_queued_mods);

  for (u32 i = 0; i < upload_queue_count; i++)
  {
    FModioQueuedModfileUpload queued_mod;
    InitializeQueuedModfileUpload(queued_mod, modio_queued_mods[i]);
    UploadQueue.Add(queued_mod);
  }

  free(modio_queued_mods);

  return UploadQueue;
}

void FModioSubsystem::SubscribeToMod(int32 ModId, FModioModDelegate SubscribeToModDelegate)
{
  FModioAsyncRequest_SubscribeToMod *Request = new FModioAsyncRequest_SubscribeToMod( this, SubscribeToModDelegate );
  modioSubscribeToMod(Request, (u32)ModId, FModioAsyncRequest_SubscribeToMod::Response);
  QueueAsyncTask( Request );
}

void FModioSubsystem::UnsubscribeFromMod(int32 ModId, FModioGenericDelegate UnsubscribeFromModDelegate)
{
  FModioAsyncRequest_UnsubscribeFromMod *Request = new FModioAsyncRequest_UnsubscribeFromMod( this, UnsubscribeFromModDelegate );
  modioUnsubscribeFromMod(Request, (u32)ModId, FModioAsyncRequest_UnsubscribeFromMod::Response);
  QueueAsyncTask( Request );
}

bool FModioSubsystem::IsCurrentUserSubscribed(int32 ModId)
{
  return modioIsCurrentUserSubscribed((u32)ModId);
}

TArray<int32> FModioSubsystem::GetCurrentUserSubscriptions()
{
  TArray<int32> CurrentUserSubscriptions;

  u32 current_user_subscriptions_count = modioGetCurrentUserSubscriptionsCount();
  u32 *current_user_subscriptions = new u32[current_user_subscriptions_count];
  modioGetCurrentUserSubscriptions(current_user_subscriptions);

  for (u32 i = 0; i < current_user_subscriptions_count; i++)
  {
    CurrentUserSubscriptions.Add(current_user_subscriptions[i]);
  }

  delete[] current_user_subscriptions;

  return CurrentUserSubscriptions;
}

void FModioSubsystem::AddModRating(int32 ModId, bool IsRatingPositive, FModioGenericDelegate AddModRatingDelegate)
{
  FModioAsyncRequest_AddModRating *Request = new FModioAsyncRequest_AddModRating( this, AddModRatingDelegate );
  modioAddModRating(Request, (u32)ModId, IsRatingPositive, FModioAsyncRequest_AddModRating::Response);
  QueueAsyncTask( Request );
}

TEnumAsByte<EModioRatingType> FModioSubsystem::GetCurrentUserModRating(int32 ModId)
{
  u32 ModRating = modioGetCurrentUserModRating((u32)ModId);
  return ConvertToModRatingType(ModRating);
}

void FModioSubsystem::GetAllModDependencies(int32 ModId, FModioModDependencyArrayDelegate GetAllModDependenciesDelegate)
{
  FModioAsyncRequest_GetAllModDependencies *Request = new FModioAsyncRequest_GetAllModDependencies( this, GetAllModDependenciesDelegate );
  modioGetAllModDependencies(Request, (u32)ModId, FModioAsyncRequest_GetAllModDependencies::Response);
  QueueAsyncTask( Request );
}

void FModioSubsystem::AddModDependencies(int32 ModId, const TArray<int32> &Dependencies, FModioGenericDelegate AddModDependenciesDelegate)
{
  FModioAsyncRequest_AddModDependencies *Request = new FModioAsyncRequest_AddModDependencies( this, AddModDependenciesDelegate );
  u32 *ModIds = new u32[Dependencies.Num()];
  for(int i = 0; i < Dependencies.Num(); i++)
  {
    ModIds[i] = Dependencies[i];
  }
  modioAddModDependencies(Request, (u32)ModId, ModIds, (u32)Dependencies.Num(), FModioAsyncRequest_AddModDependencies::Response);
  delete[] ModIds;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DeleteModDependencies(int32 ModId, const TArray<int32> &Dependencies, FModioGenericDelegate DeleteModDependenciesDelegate)
{
  FModioAsyncRequest_DeleteModDependencies *Request = new FModioAsyncRequest_DeleteModDependencies( this, DeleteModDependenciesDelegate );
  u32 *ModIds = new u32[Dependencies.Num()];
  for(int i = 0; i < Dependencies.Num(); i++)
  {
    ModIds[i] = Dependencies[i];
  }
  modioDeleteModDependencies(Request, (u32)ModId, ModIds, (u32)Dependencies.Num(), FModioAsyncRequest_DeleteModDependencies::Response);
  delete[] ModIds;
  
  QueueAsyncTask( Request );
}

void FModioSubsystem::SubmitReport(TEnumAsByte<EModioResourceType> Resource, int32 Id, TEnumAsByte<EModioReportType> Type, const FString &Name, const FString &Summary, FModioGenericDelegate SubmitReportDelegate)
{
  FModioAsyncRequest_SubmitReport *Request = new FModioAsyncRequest_SubmitReport( this, SubmitReportDelegate );
  
  FString ResourceStr = "";
  switch (Resource)
  {
  case EModioResourceType::GAMES:
    ResourceStr = "games";
    break;
  case EModioResourceType::MODS:
    ResourceStr = "mods";
    break;
  case EModioResourceType::USERS:
    ResourceStr = "users";
    break;
  default:
    // @todo: handle error
    break;
  }

  u32 CType = 0;

  switch (Type)
  {
  case EModioReportType::GENERIC:
    CType = 0;
    break;
  case EModioReportType::DMCA:
    CType = 1;
    break;
  default:
    // @todo: handle error
    break;
  }

  modioSubmitReport(Request, TCHAR_TO_UTF8(*ResourceStr), (u32)Id, CType, TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Summary), FModioAsyncRequest_SubmitReport::Response);
  
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetAllModTags(int32 ModId, FModioModTagArrayDelegate GetAllModTagsDelegate)
{
  FModioAsyncRequest_GetAllModTags *Request = new FModioAsyncRequest_GetAllModTags( this, GetAllModTagsDelegate );
  modioGetModTags(Request, (u32)ModId, FModioAsyncRequest_GetAllModTags::Response);
  QueueAsyncTask( Request );
}

void FModioSubsystem::AddModTags(int32 ModId, const TArray<FString> &Tags, FModioGenericDelegate AddModTagsDelegate)
{
  FModioAsyncRequest_AddModTags *Request = new FModioAsyncRequest_AddModTags( this, AddModTagsDelegate );
  char **ModTags = new char*[Tags.Num()];
  for(int i = 0; i < Tags.Num(); i++)
  {
    ModTags[i] = new char[Tags[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(ModTags[i], Tags[i].Len() + 1, TCHAR_TO_UTF8(*Tags[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(ModTags[i], TCHAR_TO_UTF8(*Tags[i]));
    #endif
  }
  modioAddModTags(Request, (u32)ModId, ModTags, (u32)Tags.Num(), FModioAsyncRequest_AddModTags::Response);
  for(int i = 0; i < Tags.Num(); i++)
  {
    delete[] ModTags[i];
  }
  delete[] ModTags;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DeleteModTags(int32 ModId, const TArray<FString> &Tags, FModioGenericDelegate DeleteModTagsDelegate)
{
  FModioAsyncRequest_DeleteModTags *Request = new FModioAsyncRequest_DeleteModTags( this, DeleteModTagsDelegate );
  char **ModTags = new char*[Tags.Num()];
  for(int i = 0; i < Tags.Num(); i++)
  {
    ModTags[i] = new char[Tags[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(ModTags[i], Tags[i].Len() + 1, TCHAR_TO_UTF8(*Tags[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(ModTags[i], TCHAR_TO_UTF8(*Tags[i]));
    #endif
  }
  modioDeleteModTags(Request, (u32)ModId, ModTags, (u32)Tags.Num(), FModioAsyncRequest_DeleteModTags::Response);
  for(int i = 0; i < Tags.Num(); i++)
  {
    delete[] ModTags[i];
  }
  delete[] ModTags;
  
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetAllMetadataKVP(int32 ModId, FModioMetadataKVPArrayDelegate GetAllMetadataKVPDelegate)
{
  FModioAsyncRequest_GetAllMetadataKVP *Request = new FModioAsyncRequest_GetAllMetadataKVP( this, GetAllMetadataKVPDelegate );
  modioGetAllMetadataKVP(Request, (u32)ModId, FModioAsyncRequest_GetAllMetadataKVP::Response);
  QueueAsyncTask( Request );
}

void FModioSubsystem::AddMetadataKVP(int32 ModId, const TMap<FString, FString> &MetadataKVP, FModioGenericDelegate AddMetadataKVPDelegate)
{
  FModioAsyncRequest_AddMetadataKVP *Request = new FModioAsyncRequest_AddMetadataKVP( this, AddMetadataKVPDelegate );
  char **CMetadataKVP = new char*[MetadataKVP.Num()];

  uint32 i = 0;
  for (const TPair<FString, FString>& pair : MetadataKVP)
  {
    FString StringfiedKVP = pair.Key + ":" + pair.Value;
    CMetadataKVP[i] = new char[StringfiedKVP.Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CMetadataKVP[i], StringfiedKVP.Len() + 1, TCHAR_TO_UTF8(*StringfiedKVP));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CMetadataKVP[i], TCHAR_TO_UTF8(*StringfiedKVP));
    #endif
    i++;
  }
  modioAddMetadataKVP(Request, (u32)ModId, CMetadataKVP, (u32)MetadataKVP.Num(), FModioAsyncRequest_AddMetadataKVP::Response);
  for(int j = 0; j < MetadataKVP.Num(); j++)
  {
    delete[] CMetadataKVP[j];
  }
  delete[] CMetadataKVP;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DeleteMetadataKVP(int32 ModId, const TMap<FString, FString> &MetadataKVP, FModioGenericDelegate DeleteMetadataKVPDelegate)
{
  FModioAsyncRequest_DeleteMetadataKVP *Request = new FModioAsyncRequest_DeleteMetadataKVP( this, DeleteMetadataKVPDelegate );
  char **CMetadataKVP = new char*[MetadataKVP.Num()];
  
  uint32 i = 0;
  for (const TPair<FString, FString>& pair : MetadataKVP)
  {
    FString StringfiedKVP = pair.Key + ":" + pair.Value;
    CMetadataKVP[i] = new char[StringfiedKVP.Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CMetadataKVP[i], StringfiedKVP.Len() + 1, TCHAR_TO_UTF8(*StringfiedKVP));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CMetadataKVP[i], TCHAR_TO_UTF8(*StringfiedKVP));
    #endif
    i++;
  }
  modioDeleteMetadataKVP(Request, (u32)ModId, CMetadataKVP, (u32)MetadataKVP.Num(), FModioAsyncRequest_DeleteModTags::Response);
  for(int j = 0; j < MetadataKVP.Num(); j++)
  {
    delete[] CMetadataKVP[j];
  }
  delete[] CMetadataKVP;

  QueueAsyncTask( Request );
}

void FModioSubsystem::AddModLogo(int32 ModId, const FString &LogoPath, FModioGenericDelegate AddModLogoDelegate)
{
  FModioAsyncRequest_AddModLogo *Request = new FModioAsyncRequest_AddModLogo( this, AddModLogoDelegate );
  modioAddModLogo( Request, ModId, TCHAR_TO_UTF8(*LogoPath), FModioAsyncRequest_AddModLogo::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::AddModImages(int32 ModId, const TArray<FString> &ImagePaths, FModioGenericDelegate AddModImagesDelegate)
{
  FModioAsyncRequest_AddModImages *Request = new FModioAsyncRequest_AddModImages( this, AddModImagesDelegate );
  char **CImagePaths = new char*[ImagePaths.Num()];
  for(int i = 0; i < ImagePaths.Num(); i++)
  {
    CImagePaths[i] = new char[ImagePaths[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CImagePaths[i], ImagePaths[i].Len() + 1, TCHAR_TO_UTF8(*ImagePaths[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CImagePaths[i], TCHAR_TO_UTF8(*ImagePaths[i]));
    #endif
  }
  modioAddModImages(Request, (u32)ModId, CImagePaths, (u32)ImagePaths.Num(), FModioAsyncRequest_AddModImages::Response);
  for(int i = 0; i < ImagePaths.Num(); i++)
  {
    delete[] CImagePaths[i];
  }
  delete[] CImagePaths;

  QueueAsyncTask( Request );
}

void FModioSubsystem::AddModYoutubeLinks(int32 ModId, const TArray<FString> &YoutubeLinks, FModioGenericDelegate AddModYoutubeLinksDelegate)
{
  FModioAsyncRequest_AddModYoutubeLinks *Request = new FModioAsyncRequest_AddModYoutubeLinks( this, AddModYoutubeLinksDelegate );
  char **CYoutubeLinks = new char*[YoutubeLinks.Num()];
  for(int i = 0; i < YoutubeLinks.Num(); i++)
  {
    CYoutubeLinks[i] = new char[YoutubeLinks[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CYoutubeLinks[i], YoutubeLinks[i].Len() + 1, TCHAR_TO_UTF8(*YoutubeLinks[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CYoutubeLinks[i], TCHAR_TO_UTF8(*YoutubeLinks[i]));
    #endif
  }
  modioAddModYoutubeLinks(Request, (u32)ModId, CYoutubeLinks, (u32)YoutubeLinks.Num(), FModioAsyncRequest_AddModYoutubeLinks::Response);
  for(int i = 0; i < YoutubeLinks.Num(); i++)
  {
    delete[] CYoutubeLinks[i];
  }
  delete[] CYoutubeLinks;

  QueueAsyncTask( Request );
}

void FModioSubsystem::AddModSketchfabLinks(int32 ModId, const TArray<FString> &SketchfabLinks, FModioGenericDelegate AddModSketchfabLinksDelegate)
{
  FModioAsyncRequest_AddModSketchfabLinks *Request = new FModioAsyncRequest_AddModSketchfabLinks( this, AddModSketchfabLinksDelegate );
  char **CSketchfabLinks = new char*[SketchfabLinks.Num()];
  for(int i = 0; i < SketchfabLinks.Num(); i++)
  {
    CSketchfabLinks[i] = new char[SketchfabLinks[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CSketchfabLinks[i], SketchfabLinks[i].Len() + 1, TCHAR_TO_UTF8(*SketchfabLinks[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CSketchfabLinks[i], TCHAR_TO_UTF8(*SketchfabLinks[i]));
    #endif
  }
  modioAddModSketchfabLinks(Request, (u32)ModId, CSketchfabLinks, (u32)SketchfabLinks.Num(), FModioAsyncRequest_AddModSketchfabLinks::Response);
  for(int i = 0; i < SketchfabLinks.Num(); i++)
  {
    delete[] CSketchfabLinks[i];
  }
  delete[] CSketchfabLinks;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DeleteModImages(int32 ModId, const TArray<FString> &ImagePaths, FModioGenericDelegate DeleteModImagesDelegate)
{
  FModioAsyncRequest_DeleteModImages *Request = new FModioAsyncRequest_DeleteModImages( this, DeleteModImagesDelegate );
  char **CImagePaths = new char*[ImagePaths.Num()];
  for(int i = 0; i < ImagePaths.Num(); i++)
  {
    CImagePaths[i] = new char[ImagePaths[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CImagePaths[i], ImagePaths[i].Len() + 1, TCHAR_TO_UTF8(*ImagePaths[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CImagePaths[i], TCHAR_TO_UTF8(*ImagePaths[i]));
    #endif
  }
  modioDeleteModImages(Request, (u32)ModId, CImagePaths, (u32)ImagePaths.Num(), FModioAsyncRequest_DeleteModImages::Response);
  for(int i = 0; i < ImagePaths.Num(); i++)
  {
    delete[] CImagePaths[i];
  }
  delete[] CImagePaths;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DeleteModYoutubeLinks(int32 ModId, const TArray<FString> &YoutubeLinks, FModioGenericDelegate DeleteModYoutubeLinksDelegate)
{
  FModioAsyncRequest_DeleteModYoutubeLinks *Request = new FModioAsyncRequest_DeleteModYoutubeLinks( this, DeleteModYoutubeLinksDelegate );
  char **CYoutubeLinks = new char*[YoutubeLinks.Num()];
  for(int i = 0; i < YoutubeLinks.Num(); i++)
  {
    CYoutubeLinks[i] = new char[YoutubeLinks[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CYoutubeLinks[i], YoutubeLinks[i].Len() + 1, TCHAR_TO_UTF8(*YoutubeLinks[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CYoutubeLinks[i], TCHAR_TO_UTF8(*YoutubeLinks[i]));
    #endif
  }
  modioDeleteModYoutubeLinks(Request, (u32)ModId, CYoutubeLinks, (u32)YoutubeLinks.Num(), FModioAsyncRequest_DeleteModYoutubeLinks::Response);
  for(int i = 0; i < YoutubeLinks.Num(); i++)
  {
    delete[] CYoutubeLinks[i];
  }
  delete[] CYoutubeLinks;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DeleteModSketchfabLinks(int32 ModId, const TArray<FString> &SketchfabLinks, FModioGenericDelegate DeleteModSketchfabLinksDelegate)
{
  FModioAsyncRequest_DeleteModSketchfabLinks *Request = new FModioAsyncRequest_DeleteModSketchfabLinks( this, DeleteModSketchfabLinksDelegate );
  char **CSketchfabLinks = new char*[SketchfabLinks.Num()];
  for(int i = 0; i < SketchfabLinks.Num(); i++)
  {
    CSketchfabLinks[i] = new char[SketchfabLinks[i].Len() + 1];
    #ifdef MODIO_UE4_WINDOWS_BUILD
      strcpy_s(CSketchfabLinks[i], SketchfabLinks[i].Len() + 1, TCHAR_TO_UTF8(*SketchfabLinks[i]));
    #elif defined(MODIO_UE4_MAC_BUILD) || defined(MODIO_UE4_LINUX_BUILD)
      strcpy(CSketchfabLinks[i], TCHAR_TO_UTF8(*SketchfabLinks[i]));
    #endif
  }
  modioDeleteModSketchfabLinks(Request, (u32)ModId, CSketchfabLinks, (u32)SketchfabLinks.Num(), FModioAsyncRequest_DeleteModSketchfabLinks::Response);
  for(int i = 0; i < SketchfabLinks.Num(); i++)
  {
    delete[] CSketchfabLinks[i];
  }
  delete[] CSketchfabLinks;

  QueueAsyncTask( Request );
}

void FModioSubsystem::SetModDownloadListener(FModioListenerDelegate Delegate)
{
  FModioSubsystem::ModioOnModDownloadDelegate = Delegate;
}

void FModioSubsystem::SetModfileUploadListener(FModioListenerDelegate Delegate)
{
  FModioSubsystem::ModioOnModUploadDelegate = Delegate;
}

void FModioSubsystem::SetModEventListener(FModioModEventArrayDelegate Delegate)
{
  FModioSubsystem::ModioOnModEventDelegate = Delegate;
}

TEnumAsByte<EModioModState> FModioSubsystem::GetModState(int32 ModId)
{
  u32 ModState = modioGetModState((u32)ModId);
  return ConvertToModState(ModState);
}

void FModioSubsystem::PrioritizeModDownload(int32 ModId)
{
  modioPrioritizeModDownload((u32)ModId);
}

void FModioSubsystem::DownloadModfilesById(const TArray<int32> &ModIds, FModioBooleanDelegate DownloadModfilesByIdDelegate)
{
  FModioAsyncRequest_DownloadModfilesById *Request = new FModioAsyncRequest_DownloadModfilesById( this, DownloadModfilesByIdDelegate );
  u32 *CModIds = new u32[ModIds.Num()];
  for(int i = 0; i < ModIds.Num(); i++)
  {
    CModIds[i] = ModIds[i];
  }
  modioDownloadModfilesById(Request, CModIds, (u32)ModIds.Num(), FModioAsyncRequest_DownloadModfilesById::Response);
  delete[] CModIds;

  QueueAsyncTask( Request );
}

void FModioSubsystem::DownloadSubscribedModfiles(bool UninstallUnsubscribed, FModioBooleanDelegate DownloadSubscribedModfilesDelegate)
{
  FModioAsyncRequest_DownloadSubscribedModfiles *Request = new FModioAsyncRequest_DownloadSubscribedModfiles( this, DownloadSubscribedModfilesDelegate );
  modioDownloadSubscribedModfiles(Request, UninstallUnsubscribed, FModioAsyncRequest_DownloadSubscribedModfiles::Response);
  QueueAsyncTask( Request );
}

bool FModioSubsystem::UninstallMod(int32 ModId)
{
  return modioUninstallMod((u32)ModId);
}

void onModDownload(u32 response_code, u32 mod_id)
{
  FModioSubsystem::ModioOnModDownloadDelegate.ExecuteIfBound( (int32)response_code, (int32)mod_id );
}

void onModDownloadWithAutomaticInstalls(u32 response_code, u32 mod_id)
{
  modioInstallDownloadedMods();
  FModioSubsystem::ModioOnModDownloadDelegate.ExecuteIfBound( (int32)response_code, (int32)mod_id );
}

void onModUpload(u32 response_code, u32 mod_id)
{
  FModioSubsystem::ModioOnModUploadDelegate.ExecuteIfBound( (int32)response_code, (int32)mod_id );
}

void onModEvent(ModioResponse ModioResponse, ModioModEvent* ModioEventsArray, u32 ModioEventsArraySize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );
  FModioSubsystem::ModioOnModEventDelegate.ExecuteIfBound( Response, ConvertToTArrayModEvents(ModioEventsArray, ModioEventsArraySize) );
}

void FModioSubsystem::Init( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironment, bool bInstallOnModDownload, bool bRetrieveModsFromOtherGames, bool bEnablePolling)
{
  std::streambuf *clog_backup, *cerr_backup;
  clog_backup = std::clog.rdbuf();
  cerr_backup = std::cerr.rdbuf();

  LStream Stream;
  std::clog.rdbuf(&Stream);
  std::cerr.rdbuf(&Stream);

  std::clog << "[mod.io] Initializing mod.io UE4 plugin.\n";

  check(!bInitialized);

  u32 Environment = bIsLiveEnvironment ? MODIO_ENVIRONMENT_LIVE : MODIO_ENVIRONMENT_TEST;

  TCHAR_TO_UTF8(*RootDirectory) ;
  std::clog << "[mod.io] UTF8 root path:" << TCHAR_TO_UTF8(*RootDirectory) << std::endl;
  UE_LOG(LogTemp, Log, TEXT("[mod.io] root path %s"), *RootDirectory);

  modioInit( Environment, (u32)GameId, bRetrieveModsFromOtherGames, bEnablePolling, TCHAR_TO_UTF8(*ApiKey), TCHAR_TO_UTF8(*RootDirectory) );

  if(bInstallOnModDownload)
    modioSetDownloadListener(&onModDownloadWithAutomaticInstalls);
  else
    modioSetDownloadListener(&onModDownload);
  
  modioSetUploadListener(&onModUpload);

  modioSetEventListener(&onModEvent);

  bInitialized = true;

  std::clog << "[mod.io] Finished initializing mod.io UE4 plugin.";
  std::clog.flush();
  std::cerr.flush();
  std::clog.rdbuf(clog_backup);
  std::cerr.rdbuf(cerr_backup);
}

void FModioSubsystem::QueueAsyncTask( struct FModioAsyncRequest* Request )
{
  checkf(Request, TEXT("Trying to queue up a invalid async request"));
  TSharedPtr<FModioAsyncRequest> SharedRequest = MakeShareable(Request);
  checkf(!AsyncRequests.Contains(SharedRequest), TEXT("Trying queue a async request twice"));

  AsyncRequests.Add(SharedRequest);
}

void FModioSubsystem::AsyncRequestDone( struct FModioAsyncRequest *Request )
{
  checkf(Request, TEXT("Passing in a bad request to AsyncRequestDone"));
  checkf(AsyncRequests.Contains(Request->AsShared()), TEXT("Async Request marking itself as done multiple times"));

  AsyncRequests.RemoveSwap(Request->AsShared());
}

void FModioSubsystem::Shutdown()
{
  check(bInitialized);

  // I would assume that nullptr is valid to stop the callbacks comming in
  modioSetDownloadListener(nullptr);
  modioSetUploadListener(nullptr);

  bInitialized = false;
}