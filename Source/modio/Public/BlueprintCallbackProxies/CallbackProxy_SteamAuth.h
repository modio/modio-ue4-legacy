// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_SteamAuth.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FSteamAuthResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_SteamAuth : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Base64Ticket;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FSteamAuthResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FSteamAuthResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_SteamAuth *SteamAuth( UObject *WorldContext, const FString &Base64Ticket);

  virtual void Activate() override;

  virtual void OnSteamAuthDelegate(FModioResponse Response);
};