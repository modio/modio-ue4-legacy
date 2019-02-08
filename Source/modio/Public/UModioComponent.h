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

  /* onEmailRequest */
  DECLARE_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnEmailRequestDelegate,
      int32);
  static FModioPlugin_OnEmailRequestDelegate OnEmailRequestDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnEmailRequestDynamicDelegate,
      int32,
      response_code);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailRequest"))
  FModioPlugin_OnEmailRequestDynamicDelegate OnEmailRequestDynamicDelegate;

  /* onEmailExchange */
  DECLARE_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnEmailExchangeDelegate,
      int32);
  static FModioPlugin_OnEmailExchangeDelegate OnEmailExchangeDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
      FModioPlugin_OnEmailExchangeDynamicDelegate,
      int32,
      response_code);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailExchange"))
  FModioPlugin_OnEmailExchangeDynamicDelegate OnEmailExchangeDynamicDelegate;

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

  /* onGetAllMods */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnGetAllModsDelegate,
      int32,
      TArray<FModioMod>);
  static FModioPlugin_OnGetAllModsDelegate OnGetAllModsDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnGetAllModsDynamicDelegate,
      int32,
      response_code,
      TArray<FModioMod>,
      mods);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnGetAllMods"))
  FModioPlugin_OnGetAllModsDynamicDelegate OnGetAllModsDynamicDelegate;

  /* onAddMod */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnAddModDelegate,
      int32,
      FModioMod);
  static FModioPlugin_OnAddModDelegate OnAddModDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnAddModDynamicDelegate,
      int32,
      response_code,
      FModioMod,
      mod);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnAddMod"))
  FModioPlugin_OnAddModDynamicDelegate OnAddModDynamicDelegate;

  /* onEditMod */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnEditModDelegate,
      int32,
      FModioMod);
  static FModioPlugin_OnEditModDelegate OnEditModDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnEditModDynamicDelegate,
      int32,
      response_code,
      FModioMod,
      mod);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEditMod"))
  FModioPlugin_OnEditModDynamicDelegate OnEditModDynamicDelegate;

  /* onGetUserSubscriptions */
  DECLARE_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnGetUserSubscriptionsDelegate,
      int32,
      TArray<FModioMod>);
  static FModioPlugin_OnGetUserSubscriptionsDelegate OnGetUserSubscriptionsDelegate;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
      FModioPlugin_OnGetUserSubscriptionsDynamicDelegate,
      int32,
      response_code,
      TArray<FModioMod>,
      mods);
  UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnGetUserSubscriptions"))
  FModioPlugin_OnGetUserSubscriptionsDynamicDelegate OnGetUserSubscriptionsDynamicDelegate;

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
  void OnEmailRequestDelegate_Handler(int32 response_code);
  void OnEmailExchangeDelegate_Handler(int32 response_code);
  void OnModDownloadDelegate_Handler(int32 response_code);
  void OnModUploadDelegate_Handler(int32 response_code);
  void OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FString username);
  void OnGetAllModsDelegate_Handler(int32 response_code, TArray<FModioMod> mods);
  void OnAddModDelegate_Handler(int32 response_code, FModioMod mod);
  void OnEditModDelegate_Handler(int32 response_code, FModioMod mod);
  void OnGetUserSubscriptionsDelegate_Handler(int32 response_code, TArray<FModioMod> mods);
  void OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FModioUser user);
};