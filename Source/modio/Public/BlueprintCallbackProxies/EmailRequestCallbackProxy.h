// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "EmailRequestCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FEmailRequestResult,
    FModioResponse,
    response);

UCLASS()
class MODIO_API UEmailRequestCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Email;

  // The world context object in which this call is taking place
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UEmailRequestCallbackProxy *EmailRequest(UObject *WorldContextObject, const FString& Email);

  virtual void Activate() override;

  virtual void OnEmailRequestDelegate(FModioResponse Response);
};