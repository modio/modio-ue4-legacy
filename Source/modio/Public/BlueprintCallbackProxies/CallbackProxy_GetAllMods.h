// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"
#include "Enums/ModioFilterType.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAllMods.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAllModsResult,
    FModioResponse,
    Response,
    const TArray<FModioMod> &,
    Mods);

UCLASS()
class MODIO_API UCallbackProxy_GetAllMods : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TEnumAsByte<EModioFilterType> FilterType;
  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;
  
  UPROPERTY(BlueprintAssignable)
  FGetAllModsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllModsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetAllMods *GetAllMods(UObject *WorldContext, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetAllModsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods);
};