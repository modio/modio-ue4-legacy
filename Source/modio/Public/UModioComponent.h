// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Components/ActorComponent.h"
#include "UModioComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), DisplayName = "ModioPlugin")
class MODIO_API UModioComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  void OnRegister() override;
  void OnUnregister() override;

  /* onModDownload */
  DECLARE_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnModDownloadDelegate,
      int32);
  static FModioPlugin_OnModDownloadDelegate OnModDownloadDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnModDownloadDynamicDelegate,
      int32,
      response_code);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModDownload"))
  FModioPlugin_OnModDownloadDynamicDelegate OnModDownloadDynamicDelegate;

  /* onModUpload */
  DECLARE_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnModUploadDelegate,
      int32);
  static FModioPlugin_OnModUploadDelegate OnModUploadDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnModUploadDynamicDelegate,
      int32,
      response_code);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModUpload"))
  FModioPlugin_OnModUploadDynamicDelegate OnModUploadDynamicDelegate;

  /* onGetAuthenticatedUser */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnGetAuthenticatedUserDelegate,
      int32,
      FModioUser);
  static FModioPlugin_OnGetAuthenticatedUserDelegate OnGetAuthenticatedUserDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnGetAuthenticatedUserDynamicDelegate,
      int32,
      response_code,
      FModioUser,
      user);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnGetAuthenticatedUser"))
  FModioPlugin_OnGetAuthenticatedUserDynamicDelegate OnGetAuthenticatedUserDynamicDelegate;

private:
  void OnModDownloadDelegate_Handler(int32 response_code);
  void OnModUploadDelegate_Handler(int32 response_code);
  void OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FString username);
  void OnGetUserSubscriptionsDelegate_Handler(int32 response_code, TArray<FModioMod> mods);
  void OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FModioUser user);
};