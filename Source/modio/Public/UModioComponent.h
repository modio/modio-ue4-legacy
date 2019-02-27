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

  /* onModUpload */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnModUploadDelegate,
      int32,
      int32);
  static FModioPlugin_OnModUploadDelegate OnModUploadDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnModUploadDynamicDelegate,
      int32,
      response_code,
      int32,
      mod_id);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModUpload"))
  FModioPlugin_OnModUploadDynamicDelegate OnModUploadDynamicDelegate;

private:
  void OnModDownloadDelegate_Handler(int32 response_code, int32 mod_id);
  void OnModUploadDelegate_Handler(int32 response_code, int32 mod_id);
};