// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_UnsubscribeFromMod.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FUnsubscribeFromModResult,
    FModioResponse,
    Response);

UCLASS()
class MODIO_API UCallbackProxy_UnsubscribeFromMod : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FUnsubscribeFromModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FUnsubscribeFromModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_UnsubscribeFromMod *UnsubscribeFromMod(UObject *WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnUnsubscribeFromModDelegate(FModioResponse Response);
};