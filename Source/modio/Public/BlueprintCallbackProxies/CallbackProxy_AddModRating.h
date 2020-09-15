// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_AddModRating.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FAddModRatingResult,
    FModioResponse,
    Response);

UCLASS()
class MODIO_API UCallbackProxy_AddModRating : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  bool IsRatingPositive;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FAddModRatingResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModRatingResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_AddModRating *AddModRating(UObject *WorldContext, int32 ModId, bool IsRatingPositive);

  virtual void Activate() override;

  virtual void OnAddModRatingDelegate(FModioResponse Response);
};