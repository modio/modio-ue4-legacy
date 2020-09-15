// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_SubscribeToMod.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FSubscribeToModResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UCallbackProxy_SubscribeToMod : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FSubscribeToModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FSubscribeToModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_SubscribeToMod *SubscribeToMod(UObject *WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnSubscribeToModDelegate(FModioResponse Response, FModioMod Mod);
};