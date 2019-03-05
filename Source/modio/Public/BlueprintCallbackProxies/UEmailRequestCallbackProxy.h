// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Net/OnlineBlueprintCallProxyBase.h"
#include "ModioUE4Plugin.h"
#include "Schemas/FModioResponse.h"
#include "Delegates.h"
#include "UEmailRequestCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FEmailRequestResult,
    FModioResponse,
    response);

UCLASS()
class MODIO_API UEmailRequestCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Email;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestResult OnFailure;

  FEmailRequestDelegate EmailRequestDelegate;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UEmailRequestCallbackProxy *EmailRequest(FString Email);

  virtual void Activate() override;

  virtual void OnEmailRequestDelegate(FModioResponse Response);
};