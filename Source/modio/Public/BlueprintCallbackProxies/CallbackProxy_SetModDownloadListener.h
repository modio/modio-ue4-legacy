// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioMod.h"
#include "ModioSubsystem.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_SetModDownloadListener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnModDownloadResult,
    int32,
    ResponseCode,
    int32,
    ModId);

UCLASS()
class MODIO_API UCallbackProxy_SetModDownloadListener : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FOnModDownloadResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FOnModDownloadResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_SetModDownloadListener *SetModDownloadListener(UObject *WorldContext);

  virtual void Activate() override;

  virtual void OnModDownloadDelegate(int32 ResponseCode, int32 ModId);
};