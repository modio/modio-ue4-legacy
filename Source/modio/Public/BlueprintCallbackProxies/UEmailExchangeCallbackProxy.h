// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UEmailExchangeCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FEmailExchangeResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UEmailExchangeCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString SecurityCode;

  // The world context object in which this call is taking place
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FEmailExchangeResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailExchangeResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UEmailExchangeCallbackProxy *EmailExchange( UObject *WorldContextObject, const FString &SecurityCode);

  virtual void Activate() override;

  virtual void OnEmailExchangeDelegate(FModioResponse Response);
};