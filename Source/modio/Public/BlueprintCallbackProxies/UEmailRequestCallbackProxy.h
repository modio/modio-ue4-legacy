// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UEmailRequestCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FEmailRequestCheckResult,
    int32,
    response_code);

UCLASS()
class MODIO_API UEmailRequestCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString email;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestCheckResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestCheckResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static UEmailRequestCallbackProxy *EmailRequest(FString email);

  virtual void Activate() override;

  void OnEmailRequestDelegate(int32 Result);
};