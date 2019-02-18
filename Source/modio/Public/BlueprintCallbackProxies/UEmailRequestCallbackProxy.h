// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Schemas/FModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UEmailRequestCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FEmailRequestCheckResult,
    FModioResponse,
    response);

UCLASS()
class MODIO_API UEmailRequestCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Email;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestCheckResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestCheckResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UEmailRequestCallbackProxy *EmailRequest(FString Email);

  virtual void Activate() override;

  void OnEmailRequestDelegate(FModioResponse Response);
};