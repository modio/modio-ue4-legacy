// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Customizables/ModioFilterCreator.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "CallbackProxy_GetUserSubscriptions.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetUserSubscriptionsResult,
    FModioResponse,
    Response,
    const TArray<FModioMod> &,
    Mods);

UCLASS()
class MODIO_API UCallbackProxy_GetUserSubscriptions : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioFilterCreator FilterCreator;
  TArray<FString> ModTags;
  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetUserSubscriptionsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserSubscriptionsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetUserSubscriptions *GetUserSubscriptions(UObject *WorldContext, FModioFilterCreator FilterCreator, TArray<FString> ModTags, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserSubscriptionsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods);
};