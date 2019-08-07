// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"
#include "Customizables/ModioFilterCreator.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAllModsFiltered.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAllModsFilteredResult,
    FModioResponse,
    Response,
    const TArray<FModioMod> &,
    Mods);

UCLASS()
class MODIO_API UCallbackProxy_GetAllModsFiltered : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioFilterCreator Filter;
  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;
  
  UPROPERTY(BlueprintAssignable)
  FGetAllModsFilteredResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllModsFilteredResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetAllModsFiltered *GetAllModsFiltered(UObject *WorldContext, FModioFilterCreator Filter, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetAllModsFilteredDelegate(FModioResponse Response, const TArray<FModioMod> &Mods);
};