// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Schemas/FModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UEmailExchangeCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FEmailExchangeCheckResult,
    FModioResponse,
    response);

UCLASS()
class MODIO_API UEmailExchangeCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString SecurityCode;

  UPROPERTY(BlueprintAssignable)
  FEmailExchangeCheckResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailExchangeCheckResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UEmailExchangeCallbackProxy *EmailExchange(FString SecurityCode);

  virtual void Activate() override;

  void OnEmailExchangeDelegate(FModioResponse Response);
};