// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Customizables/ModioModCreator.h"
#include "Enums/ModioMaturityOption.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_AddMod.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FAddModResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UCallbackProxy_AddMod : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioModCreator ModCreator;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FAddModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_AddMod *AddMod(UObject *WorldContext, FModioModCreator ModCreator);

  virtual void Activate() override;

  virtual void OnAddModDelegate(FModioResponse Response, FModioMod Mod);
};