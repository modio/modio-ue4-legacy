// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Components/ActorComponent.h"
#include "ModioComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), DisplayName = "ModioPlugin")
class MODIO_API UModioComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  void OnRegister() override;
  void OnUnregister() override;

  /* onModDownload */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnModDownloadDelegate,
      int32,
      int32);
  static FModioPlugin_OnModDownloadDelegate OnModDownloadDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnModDownloadDynamicDelegate,
      int32,
      response_code,
      int32,
      mod_id);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModDownload"))
  FModioPlugin_OnModDownloadDynamicDelegate OnModDownloadDynamicDelegate;

  /* onModfileUpload */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnModfileUploadDelegate,
      int32,
      int32);
  static FModioPlugin_OnModfileUploadDelegate OnModfileUploadDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnModfileUploadDynamicDelegate,
      int32,
      response_code,
      int32,
      mod_id);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModfileUpload"))
  FModioPlugin_OnModfileUploadDynamicDelegate OnModfileUploadDynamicDelegate;

private:
  void OnModDownloadDelegate_Handler(int32 response_code, int32 mod_id);
  void OnModfileUploadDelegate_Handler(int32 response_code, int32 mod_id);
};