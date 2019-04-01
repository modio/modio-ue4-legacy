#include "ModioSubsystem.h"
#include "ModioHWrapper.h"
#include "ModioPublic.h"
#include "ModioSettings.h"
#include "ModioModule.h"
#include "ModioUE4Utility.h"
#include "Schemas/ModioResponse.h"
#include "ModioCallbacks.h"

FModioSubsystem::FModioSubsystem() :
  bInitialized(false)
{
}

FModioSubsystem::~FModioSubsystem()
{
  check(!bInitialized);
}

FModioSubsystemPtr FModioSubsystem::Create( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironent )
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

  FString GameDirectory = FPaths::ConvertRelativePathToFull( FPaths::ProjectDir() );
  GameDirectory += RootDirectory;

  FModioSubsystemPtr Modio = MakeShared<FModioSubsystem, ESPMode::Fast>();
  Modio->Init( GameDirectory, GameId, ApiKey, bIsLiveEnvironent );

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

void FModioSubsystem::EmailExchange( const FString &SecurityCode, FModioGenericDelegate ExchangeDelegate )
{
  FModioAsyncRequest_EmailExchange *Request = new FModioAsyncRequest_EmailExchange( this, ExchangeDelegate );
  modioEmailRequest( Request, TCHAR_TO_UTF8(*SecurityCode), FModioAsyncRequest_EmailExchange::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::EmailRequest( const FString &Email, FModioGenericDelegate ExchangeDelegate )
{
  FModioAsyncRequest_EmailRequest *Request = new FModioAsyncRequest_EmailRequest( this, ExchangeDelegate );
  modioEmailRequest( Request, TCHAR_TO_UTF8(*Email), FModioAsyncRequest_EmailRequest::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetAllMods(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, FModioModArrayDelegate GetAllModsDelegate)
{
  FModioAsyncRequest_GetAllMods *Request = new FModioAsyncRequest_GetAllMods( this, GetAllModsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioFilterCreator(FilterType, Limit, Offset, modio_filter_creator);
  modioGetAllMods(this, modio_filter_creator, FModioAsyncRequest_GetAllMods::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetAuthenticatedUser(FModioUserDelegate GetAuthenticatedUserDelegate)
{
  FModioAsyncRequest_GetAuthenticatedUser *Request = new FModioAsyncRequest_GetAuthenticatedUser( this, GetAuthenticatedUserDelegate );
  modioGetAuthenticatedUser(this, FModioAsyncRequest_GetAuthenticatedUser::Response);
  QueueAsyncTask( Request );
}

void FModioSubsystem::GetUserSubscriptions(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, FModioModArrayDelegate GetUserSubscriptionsDelegate)
{
  FModioAsyncRequest_GetUserSubscriptions *Request = new FModioAsyncRequest_GetUserSubscriptions( this, GetUserSubscriptionsDelegate );
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioFilterCreator(FilterType, Limit, Offset, modio_filter_creator);
  modioGetUserSubscriptions(this, modio_filter_creator, FModioAsyncRequest_GetUserSubscriptions::Response);
  modioFreeFilter(&modio_filter_creator);
  QueueAsyncTask( Request );
}

void FModioSubsystem::Process()
{
  modioProcess();
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

void FModioSubsystem::Init( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironment )
{
  check(!bInitialized);

  u32 Environment = bIsLiveEnvironment ? MODIO_ENVIRONMENT_LIVE : MODIO_ENVIRONMENT_TEST;
  
  modioInit( Environment, (u32)GameId, TCHAR_TO_UTF8(*ApiKey), TCHAR_TO_UTF8(*RootDirectory) );

  modioSetDownloadListener(&onModInstalled);
  modioSetUploadListener(&onAddModfile);

  bInitialized = true;
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


namespace ModioCallback
{
}