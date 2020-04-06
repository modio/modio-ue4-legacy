// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DownloadSubscribedModfiles.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
FDownloadSubscribedModfilesResult,
FModioResponse,
response,
bool,
mods_are_updated );

UCLASS()
class MODIO_API UCallbackProxy_DownloadSubscribedModfiles : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  bool UninstallUnsubscribed;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDownloadSubscribedModfilesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDownloadSubscribedModfilesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DownloadSubscribedModfiles *DownloadSubscribedModfiles( UObject *WorldContext, bool UninstallUnsubscribed );

  virtual void Activate() override;

  virtual void OnDownloadSubscribedModfilesDelegate(FModioResponse Response, bool ModsAreUpdated);
};