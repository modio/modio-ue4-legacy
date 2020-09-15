// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioMod.h"
#include "ModioSubsystem.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_SetModfileUploadListener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnModUploadResult,
    int32,
    ResponseCode,
    int32,
    ModId);

UCLASS()
class MODIO_API UCallbackProxy_SetModfileUploadListener : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FOnModUploadResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FOnModUploadResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_SetModfileUploadListener *SetModfileUploadListener(UObject *WorldContext);

  virtual void Activate() override;

  virtual void OnModUploadDelegate(int32 ResponseCode, int32 ModId);
};