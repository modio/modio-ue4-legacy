// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Enums/ModioFilterType.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "GetUserSubscriptionsCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetUserSubscriptionsResult,
    FModioResponse,
    Response,
    const TArray<FModioMod> &,
    Mods);

UCLASS()
class MODIO_API UGetUserSubscriptionsCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TEnumAsByte<EModioFilterType> FilterType;
  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetUserSubscriptionsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserSubscriptionsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UGetUserSubscriptionsCallbackProxy *GetUserSubscriptions(UObject *WorldContextObject, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserSubscriptionsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods);
};