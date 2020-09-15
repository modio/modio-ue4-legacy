// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_EmailRequest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FEmailRequestResult,
    FModioResponse,
    response);

UCLASS()
class MODIO_API UCallbackProxy_EmailRequest : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Email;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEmailRequestResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_EmailRequest *EmailRequest(UObject *WorldContext, const FString& Email);

  virtual void Activate() override;

  virtual void OnEmailRequestDelegate(FModioResponse Response);
};