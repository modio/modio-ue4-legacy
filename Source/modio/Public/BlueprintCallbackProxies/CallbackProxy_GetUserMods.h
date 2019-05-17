// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Enums/ModioFilterType.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetUserMods.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetUserModsResult,
    FModioResponse,
    Response,
    const TArray<FModioMod> &,
    Mods);

UCLASS()
class MODIO_API UCallbackProxy_GetUserMods : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TEnumAsByte<EModioFilterType> FilterType;
  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetUserModsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserModsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetUserMods *GetUserMods(UObject *WorldContext, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserModsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods);
};