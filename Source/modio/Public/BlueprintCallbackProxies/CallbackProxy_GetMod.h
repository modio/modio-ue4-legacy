// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetMod.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetModResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UCallbackProxy_GetMod : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;
  
  UPROPERTY(BlueprintAssignable)
  FGetModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetMod *GetMod(UObject *WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnGetModDelegate(FModioResponse Response, FModioMod Mod);
};