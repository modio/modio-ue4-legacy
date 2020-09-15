// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioRating.h"
#include "Enums/ModioModSortType.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetUserRatings.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetUserRatingsResult,
    FModioResponse,
    Response,
    const TArray<FModioRating> &,
    Ratings);

UCLASS()
class MODIO_API UCallbackProxy_GetUserRatings : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetUserRatingsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserRatingsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetUserRatings *GetUserRatings(UObject *WorldContext, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserRatingsDelegate(FModioResponse Response, const TArray<FModioRating> &Ratings);
};