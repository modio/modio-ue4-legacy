// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Customizables/ModioModCreator.h"
#include "ModioUE4Plugin.h"
#include "Enums/ModioMaturityOption.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "AddModCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FAddModResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UAddModCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioModCreator ModCreator;

  UPROPERTY(BlueprintAssignable)
  FAddModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UAddModCallbackProxy *AddMod(FModioModCreator ModCreator);

  virtual void Activate() override;

  virtual void OnAddModDelegate(FModioResponse Response, FModioMod Mod);
};