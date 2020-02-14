// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "Schemas/ModioResponse.h"
#include "Customizables/ModioModCreator.h"
#include "Customizables/ModioFilterCreator.h"
#include "Customizables/ModioModEditor.h"
#include "Customizables/ModioModfileCreator.h"
#include "Schemas/ModioInstalledMod.h"
#include "Schemas/ModioQueuedModDownload.h"
#include "Schemas/ModioQueuedModfileUpload.h"
#include "Schemas/ModioModEvent.h"
#include "Enums/ModioModSortType.h"
#include "Enums/ModioModState.h"
#include "Enums/ModioRatingType.h"
#include "Enums/ModioReportType.h"
#include "Enums/ModioResourceType.h"
#include "ModioPackage.h"
#include "ModioPackage.h"
#include "AsyncRequest/ModioAsyncRequest_AddMod.h"
#include "AsyncRequest/ModioAsyncRequest_AddModDependencies.h"
#include "AsyncRequest/ModioAsyncRequest_AddModRating.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModDependencies.h"
#include "AsyncRequest/ModioAsyncRequest_EditMod.h"
#include "AsyncRequest/ModioAsyncRequest_EmailExchange.h"
#include "AsyncRequest/ModioAsyncRequest_EmailRequest.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllModDependencies.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllMods.h"
#include "AsyncRequest/ModioAsyncRequest_GetAuthenticatedUser.h"
#include "AsyncRequest/ModioAsyncRequest_GetMod.h"
#include "AsyncRequest/ModioAsyncRequest_GetUserEvents.h"
#include "AsyncRequest/ModioAsyncRequest_GetUserSubscriptions.h"
#include "AsyncRequest/ModioAsyncRequest_GetUserMods.h"
#include "AsyncRequest/ModioAsyncRequest_GetUserModfiles.h"
#include "AsyncRequest/ModioAsyncRequest_GetUserRatings.h"
#include "AsyncRequest/ModioAsyncRequest_SubscribeToMod.h"
#include "AsyncRequest/ModioAsyncRequest_UnsubscribeFromMod.h"
#include "AsyncRequest/ModioAsyncRequest_SteamAuth.h"
#include "AsyncRequest/ModioAsyncRequest_SubmitReport.h"
#include "AsyncRequest/ModioAsyncRequest_GalaxyAuth.h"
#include "AsyncRequest/ModioAsyncRequest_OculusAuth.h"
#include "AsyncRequest/ModioAsyncRequest_AddModTags.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModTags.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllModTags.h"
#include "AsyncRequest/ModioAsyncRequest_AddMetadataKVP.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteMetadataKVP.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllMetadataKVP.h"
#include "AsyncRequest/ModioAsyncRequest_AddModLogo.h"
#include "AsyncRequest/ModioAsyncRequest_AddModImages.h"
#include "AsyncRequest/ModioAsyncRequest_AddModYoutubeLinks.h"
#include "AsyncRequest/ModioAsyncRequest_AddModSketchfabLinks.h"
#include "AsyncRequest/ModioAsyncRequest_CheckIfModsAreUpdated.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModImages.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModYoutubeLinks.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModSketchfabLinks.h"
#include "Int64.h"

typedef TSharedPtr<struct FModioSubsystem, ESPMode::Fast> FModioSubsystemPtr;

/**
 * Interface for the modio c++ UE4 API. Please note that this class shouldn't
 * hold any references to any UObjects derived classes, as it is right now, as it's
 * not exposed to the GC. Reference objects with WeakObjectPointer if you want to
 * hold references to Object/Actors. And keep other pointers with Shared/Unique ptrs
 */
struct MODIO_API FModioSubsystem : public TSharedFromThis<FModioSubsystem, ESPMode::Fast>
{
public:
  static FModioSubsystemPtr Get(UWorld *World);

  virtual ~FModioSubsystem();
  
  // Process
  
  /** Process callbacks in an asyncronous way */
  void Process();

  /** Manually poll user and installed mods events */
  void PollEvents();

  // Config

  /** Change the the poll interval in wich mod updates will be processed */
  void SetModEventsPollInterval(int32 IntervalInSeconds);
  /** Change the the poll interval in wich user updates will be processed, such as mod installs and uninstalls */
  void SetUserEventsPollInterval(int32 IntervalInSeconds);

  // Auth
  
  /** Request an email from to the mod.io backend */
  void EmailRequest(const FString &Email, FModioGenericDelegate EmailRequestDelegate);
  /** Send your Security code to the backend */
  void EmailExchange(const FString &SecurityCode, FModioGenericDelegate EmailExchangeDelegate);
  /** Log in to mod.io on behalf of a Steam Galaxy user */
  void SteamAuth(const FString &Base64Ticket, FModioGenericDelegate SteamAuthDelegate);
  /** Log in to mod.io on behalf of a GOG Galaxy user */
  void GalaxyAuth(const FString &Appdata, FModioGenericDelegate GalaxyAuthDelegate);
  /** Log in to mod.io on behalf of a Oculus user */
  void OculusAuth(const FString &Nonce, const FString &OculusUserId, const FString &AccessToken, const FString &Email, int32 DateExpires, FModioGenericDelegate GalaxyAuthDelegate);
  /** Logs out the current user from mod.io */  
  void Logout();
  /** Returns true if there is a user currently logged in */  
  bool IsLoggedIn();
  /** Returns the currently logged in user */  
  FModioUser CurrentUser();
  /** Authenticates by providing an user access token directly */  
  void AuthenticateViaToken(const FString& AccessToken);

  // Mod creation and edition
  /** Creates a new mod profile on mod.io */
  void AddMod(const FModioModCreator &ModCreator, FModioModDelegate AddModDelegate);
  /** Edits an already existing mod profile on mod.io */
  void EditMod(uint32 ModId, const FModioModEditor &ModEditor, FModioModDelegate EditModDelegate);

  // Mod browsing
  /** Request mod information for a search */
  void GetAllMods(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, FModioModArrayDelegate GetAllModsDelegate);
  /** Request mod information for a single mod */
  void GetMod(uint32 ModId, const FModioModDelegate ModDelegate);
  
  // Get your own information
  /** Request the authenticated user information */
  void GetAuthenticatedUser(FModioUserDelegate GetAuthenticatedUserDelegate);
  /** Returns the mods the logged in user has subscribed */
  void GetUserSubscriptions(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, FModioModArrayDelegate GetUserSubscriptionsDelegate);
  /** Returns the mods the authenticated user owns */
  void GetUserMods(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, FModioModArrayDelegate GetUserModsDelegate);
  /** Returns the modfiles the authenticated user owns */
  void GetUserModfiles(int32 Limit, int32 Offset, FModioModfileArrayDelegate GetUserModfilesDelegate);
  /** Returns the events related to the authenticated user */
  void GetUserEvents(int32 Limit, int32 Offset, FModioUserEventArrayDelegate GetUserEventsDelegate);
  /** Returns the ratings submited by the authenticated user */
  void GetUserRatings(int32 Limit, int32 Offset, FModioRatingArrayDelegate GetUserRatingsDelegate);

  // Downloads and installs
  /** Downloads an specific mod */
  void DownloadMod(int32 ModId);
  /** Returns information of a mod installed locally */
  FModioInstalledMod GetInstalledMod(int32 ModId);
  /** Returns an array containing information of the mods installed locally */
  TArray<FModioInstalledMod> GetAllInstalledMods();
  /** Returns an array containing the downloaded mods still not installed */
  TArray<int32> GetAllDownloadedMods();
  /** Returns an array containing the download queue information */
  TArray<FModioQueuedModDownload> GetModDownloadQueue();
  /** Installs the downloaded mods, this is called automatically on startup but can be triggered at any time */
  void InstallDownloadedMods();
  /** Adds a new modfile to the upload queue */
  void AddModfile(int32 ModId, FModioModfileCreator ModfileCreator);
  /** Returns an array containing the upload queue infromation */
  TArray<FModioQueuedModfileUpload> GetModfileUploadQueue();
  /** Callback triggered every time a mod is downloaded locally from mod.io */
  void SetModDownloadListener(FModioListenerDelegate Delegate);
  /** Callback triggered every time a local mod finished uploading to mod.io */
  void SetModfileUploadListener(FModioListenerDelegate Delegate);
  /** Callback triggered every time an event is found mod.io */
  void SetModEventListener(FModioModEventArrayDelegate Delegate);
  /** Returns the state of the corresponding mod */  
  TEnumAsByte<EModioModState> GetModState(int32 ModId);
  /** Places the given mod at the top of the donload queue */
  void PrioritizeModDownload(int32 ModId);
  /** The returns True in case all mods are up to date. If not, returns false and the mods that needs an update are added to the download queue. */
  void CheckIfModsAreUpdated(const TArray<int32> &ModIds, FModioBooleanDelegate CheckIfModsAreUpdatedDelegate);

  // Mod Subscription
  /** Subscribes to the corresponding mod */
  void SubscribeToMod(int32 ModId, FModioModDelegate SubscribeToModDelegate);
  /** Unsubscribes from the corresponding mod */
  void UnsubscribeFromMod(int32 ModId, FModioGenericDelegate UnsubscribeFromModDelegate);
  /** Returns true if the current user is subscribed to the given mod */
  bool IsCurrentUserSubscribed(int32 ModId);
  /** Get the list of mods that the current user is subscribed */
  TArray<int32> GetCurrentUserSubscriptions();

  // Mod Rating
  /** Rate the corresponding mod */
  void AddModRating(int32 ModId, bool IsRatingPositive, FModioGenericDelegate AddModRatingDelegate);
  /** Get the current users rating corresponding to the given mod */
  TEnumAsByte<EModioRatingType> GetCurrentUserModRating(int32 ModId);

  // Mod Dependencies
  /** Request all the dependencies from a mod */
  void GetAllModDependencies(int32 ModId, FModioModDependencyArrayDelegate GetAllModDependenciesDelegate);
  /** Add the provided dependencies to a corresponding mod */
  void AddModDependencies(int32 ModId, const TArray<int32> &Dependencies, FModioGenericDelegate AddModDependenciesDelegate);
  /** Deletes all the provided dependencies from the corresponding mod */
  void DeleteModDependencies(int32 ModId, const TArray<int32> &Dependencies, FModioGenericDelegate DeleteModDependenciesDelegate);

  // Reports
  /** Submits a report on any resource to mod.io */
  void SubmitReport(TEnumAsByte<EModioResourceType> Resource, int32 Id, TEnumAsByte<EModioReportType> Report, const FString &Name, const FString &Summary, FModioGenericDelegate SubmitReportDelegate);

  // Mod Tags
  /** Request all the tags from a mod */
  void GetAllModTags(int32 ModId, FModioModTagArrayDelegate GetAllModTagsDelegate);
  /** Assign the provided tags to a corresponding mod */
  void AddModTags(int32 ModId, const TArray<FString> &Tags, FModioGenericDelegate AddModTagsDelegate);
  /** Deletes all the provided tags from the corresponding mod */
  void DeleteModTags(int32 ModId, const TArray<FString> &Tags, FModioGenericDelegate DeleteModTagsDelegate);

  // Mod MetadataKVP
  /** Request all the metadata kvp from a mod */
  void GetAllMetadataKVP(int32 ModId, FModioMetadataKVPArrayDelegate GetAllMetadataKVPDelegate);
  /** Assign the provided metadata kvp to a corresponding mod */
  void AddMetadataKVP(int32 ModId, const TMap<FString, FString> &MetadataKVP, FModioGenericDelegate AddMetadataKVPDelegate);
  /** Deletes all the provided metadata kvp from the corresponding mod */
  void DeleteMetadataKVP(int32 ModId, const TMap<FString, FString> &MetadataKVP, FModioGenericDelegate DeleteMetadataKVPDelegate);

  // Media Methods
  /** Adds a new logo image to the corresponding mod */
  void AddModLogo(int32 ModId, const FString &LogoPath, FModioGenericDelegate AddModLogoDelegate);
  /** Add images to the corresponding mod */
  void AddModImages(int32 ModId, const TArray<FString> &ImagePaths, FModioGenericDelegate AddModImagesDelegate);
  /** Add youtube links to the corresponding mod */
  void AddModYoutubeLinks(int32 ModId, const TArray<FString> &YoutubeLinks, FModioGenericDelegate AddModYoutubeLinksDelegate);
  /** Add sketchfab to the corresponding mod */
  void AddModSketchfabLinks(int32 ModId, const TArray<FString> &SketchfabLinks, FModioGenericDelegate AddModSketchfabLinksDelegate);
  /** Delete images from the corresponding mod */
  void DeleteModImages(int32 ModId, const TArray<FString> &ImagePaths, FModioGenericDelegate AddModImagesDelegate);
  /** Delete youtube links from the corresponding mod */
  void DeleteModYoutubeLinks(int32 ModId, const TArray<FString> &YoutubeLinks, FModioGenericDelegate AddModYoutubeLinksDelegate);
  /** Delete sketchfab from the corresponding mod */
  void DeleteModSketchfabLinks(int32 ModId, const TArray<FString> &SketchfabLinks, FModioGenericDelegate AddModSketchfabLinksDelegate);
  
  /** Download and upload delegate listeners */
  static FModioListenerDelegate ModioOnModDownloadDelegate;
  static FModioListenerDelegate ModioOnModUploadDelegate;
  static FModioModEventArrayDelegate ModioOnModEventDelegate;

protected:
  friend class FModioModule;
  static FModioSubsystemPtr Create(const FString &RootDirectory, bool bRootDirectoryIsInUserSettingsDirectory, uint32 GameId, const FString &ApiKey, bool bIsLiveEnvironment, bool bInstallOnModDownload, bool bRetrieveModsFromOtherGames);

  /** Queue up a new async request and take ownership of the memory */
  void QueueAsyncTask(struct FModioAsyncRequest *Request);
  PACKAGE_SCOPE :
  /** Called by the async request when it's done */
  void
  AsyncRequestDone(struct FModioAsyncRequest *Request);

  /** Should only be create from our create function */
  FModioSubsystem();

  /** Can be called multiple times during a session, as long as it's properly paired with it's shutdown */
  void Init(const FString &RootDirectory, uint32 GameId, const FString &ApiKey, bool bIsLiveEnvironment, bool bInstallOnModDownload, bool bRetrieveModsFromOtherGames);
  
  /** Properly shutdowns modio */
  void Shutdown();

private:
  /** All running async requests */
  TArray<TSharedPtr<struct FModioAsyncRequest>> AsyncRequests;

  /** Are we initialized */
  uint8 bInitialized : 1;
};