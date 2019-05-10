#pragma once

#include "CoreMinimal.h"
#include "ModioResponse.h"
#include "Customizables/ModioModCreator.h"
#include "Customizables/ModioModEditor.h"
#include "Customizables/ModioModfileCreator.h"
#include "Schemas/ModioInstalledMod.h"
#include "Schemas/ModioQueuedModDownload.h"
#include "Schemas/ModioQueuedModfileUpload.h"
#include "Enums/ModioFilterType.h"
#include "ModioPackage.h"
#include "ModioPackage.h"
#include "AsyncRequest/ModioAsyncRequest_AddMod.h"
#include "AsyncRequest/ModioAsyncRequest_AddModDependencies.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModDependencies.h"
#include "AsyncRequest/ModioAsyncRequest_EditMod.h"
#include "AsyncRequest/ModioAsyncRequest_EmailExchange.h"
#include "AsyncRequest/ModioAsyncRequest_EmailRequest.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllModDependencies.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllMods.h"
#include "AsyncRequest/ModioAsyncRequest_GetAuthenticatedUser.h"
#include "AsyncRequest/ModioAsyncRequest_GetUserSubscriptions.h"
#include "AsyncRequest/ModioAsyncRequest_SubscribeToMod.h"
#include "AsyncRequest/ModioAsyncRequest_UnsubscribeFromMod.h"
#include "AsyncRequest/ModioAsyncRequest_GalaxyAuth.h"
#include "AsyncRequest/ModioAsyncRequest_AddModTags.h"
#include "AsyncRequest/ModioAsyncRequest_DeleteModTags.h"
#include "AsyncRequest/ModioAsyncRequest_GetAllModTags.h"

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

  /** Request an email from to the mod.io backend */
  void EmailRequest(const FString &Email, FModioGenericDelegate EmailRequestDelegate);

  /** Send your Security code to the backend */
  void EmailExchange(const FString &SecurityCode, FModioGenericDelegate EmailExchangeDelegate);

  /** Creates a new mod profile on mod.io */
  void AddMod(const FModioModCreator &ModCreator, FModioModDelegate AddModDelegate);

  /** Edits an already existing mod profile on mod.io */
  void EditMod(uint32 ModId, const FModioModEditor &ModEditor, FModioModDelegate EditModDelegate);

  /** Request mod information */
  void GetAllMods(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, FModioModArrayDelegate GetAllModsDelegate);

  /** Request the currently logged in user information */
  void GetAuthenticatedUser(FModioUserDelegate GetAuthenticatedUserDelegate);

  /** Returns the mods the logged in user has subscribed */
  void GetUserSubscriptions(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, FModioModArrayDelegate GetUserSubscriptionsDelegate);

  /** Log in to mod.io on behalf of a GOG Galaxy user */
  void GalaxyAuth(const FString &Appdata, FModioGenericDelegate GalaxyAuthDelegate);

  /** Log in to mod.io on behalf of a Steam user */
  //void SteamAuth(const FString &Appdata, FModioGenericDelegate GalaxyAuthDelegate);

  /** Process callbacks in an asyncronous way */
  void Process();

  // Authentication

  /** Logs out the current user from mod.io */  
  void Logout();
  /** Returns true if there is a user currently logged in */  
  bool IsLoggedIn();
  /** Returns the currently logged in user */  
  FModioUser CurrentUser();

  // Downloads and installs

  /** Returns an array containing the installed mods information */
  TArray<FModioInstalledMod> GetAllInstalledMods();
  /** Returns an array containing the download queue information */
  TArray<FModioQueuedModDownload> GetModDownloadQueue();
  /** Installs the downloaded mods, this is called automatically on startup but can be triggered at any time */
  void InstallDownloadedMods();
  /** Adds a new modfile to the upload queue */
  void AddModfile(int32 ModId, FModioModfileCreator ModfileCreator);
  /** Returns an array containing the upload queue infromation */
  TArray<FModioQueuedModfileUpload> GetModfileUploadQueue();

  //Mod Subscription

  /** Subscribes to the corresponding mod */
  void SubscribeToMod(int32 ModId, FModioModDelegate SubscribeToModDelegate);
  /** Unsubscribes from the corresponding mod */
  void UnsubscribeFromMod(int32 ModId, FModioGenericDelegate UnsubscribeFromModDelegate);

  //Mod Dependencies
  /** Request all the dependencies from a mod */
  void GetAllModDependencies(int32 ModId, FModioModDependencyArrayDelegate GetAllModDependenciesDelegate);
  /** Add the provided dependencies to a corresponding mod */
  void AddModDependencies(int32 ModId, const TArray<int32> &Dependencies, FModioGenericDelegate AddModDependenciesDelegate);
  /** Deletes all the provided dependencies from the corresponding mod */
  void DeleteModDependencies(int32 ModId, const TArray<int32> &Dependencies, FModioGenericDelegate DeleteModDependenciesDelegate);

  //Mod Tags
  /** Request all the tags from a mod */
  void GetAllModTags(int32 ModId, FModioModTagsArrayDelegate GetAllModTagsDelegate);
  /** Assign the provided tags to a corresponding mod */
  void AddModTags(int32 ModId, const TArray<FString> &Tags, FModioGenericDelegate AddModTagsDelegate);
  /** Deletes all the provided tags from the corresponding mod */
  void DeleteModTags(int32 ModId, const TArray<FString> &Tags, FModioGenericDelegate DeleteModTagsDelegate);

protected:
  friend class FModioModule;
  static FModioSubsystemPtr Create(const FString &RootDirectory, uint32 GameId, const FString &ApiKey, bool bIsLiveEnvironment);

  /** Queue up a new async request and take ownership of the memory */
  void QueueAsyncTask(struct FModioAsyncRequest *Request);
  PACKAGE_SCOPE :
      /** Called by the async request when it's done */
      void
      AsyncRequestDone(struct FModioAsyncRequest *Request);

  /** Should only be create from our create function */
  FModioSubsystem();

  /** Can be called multiple times during a session, as long as it's properly paired with it's shutdown */
  void Init(const FString &RootDirectory, uint32 GameId, const FString &ApiKey, bool bIsLiveEnvironent);

  /** Properly shutdowns modio */
  void Shutdown();

private:
  /** All running async requests */
  TArray<TSharedPtr<struct FModioAsyncRequest>> AsyncRequests;

  /** Are we initialized */
  uint8 bInitialized : 1;
};