// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Schemas/FModioResponse.h"
#include "Schemas/FModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UGetUserSubscriptionsCallbackProxy.generated.h"

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

  UPROPERTY(BlueprintAssignable)
  FGetUserSubscriptionsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserSubscriptionsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UGetUserSubscriptionsCallbackProxy *GetUserSubscriptions(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserSubscriptionsDelegate(FModioResponse Response, TArray<FModioMod>);
};