// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioModEvent.h"
#include "ModioSubsystem.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_SetModEventListener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnModEventResult,
    FModioResponse,
    Response,
    const TArray<FModioModEvent> &,
    ModEvents);

UCLASS()
class MODIO_API UCallbackProxy_SetModEventListener : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FOnModEventResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FOnModEventResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_SetModEventListener *SetModEventListener(UObject *WorldContext);

  virtual void Activate() override;

  virtual void OnModEventDelegate(FModioResponse Response, const TArray<FModioModEvent> &ModEvents);
};