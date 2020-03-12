// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Int64.h"
#include "CallbackProxy_OculusAuth.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FOculusAuthResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_OculusAuth : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Nonce;
  FString OculusUserId;
  FString AccessToken;
  FString Email;
  FString Device;
  int32 DateExpires;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FOculusAuthResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FOculusAuthResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_OculusAuth *OculusAuth( UObject *WorldContext, const FString &Nonce, const FString &OculusUserId, const FString &AccessToken, const FString &Email, const FString &Device, int32 DateExpires);

  virtual void Activate() override;

  virtual void OnOculusAuthDelegate(FModioResponse Response);
};