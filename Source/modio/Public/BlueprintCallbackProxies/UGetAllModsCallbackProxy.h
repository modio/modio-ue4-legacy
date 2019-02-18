// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Enums/EModioFilterType.h"
#include "Schemas/FModioResponse.h"
#include "Schemas/FModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UGetAllModsCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAllModsCallbackCheckResult,
    FModioResponse,
    Response,
    const TArray<FModioMod> &,
    Mods);

UCLASS()
class MODIO_API UGetAllModsCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TEnumAsByte<EModioFilterType> FilterType;
  int32 Limit;
  int32 Offset;

  UPROPERTY(BlueprintAssignable)
  FGetAllModsCallbackCheckResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllModsCallbackCheckResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UGetAllModsCallbackProxy *GetAllMods(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset);

  virtual void Activate() override;

  void OnGetAllModsDelegate(FModioResponse Response, TArray<FModioMod> Mods);
};