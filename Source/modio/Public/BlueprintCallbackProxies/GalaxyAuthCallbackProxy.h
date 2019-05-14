// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "GalaxyAuthCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FGalaxyAuthResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UGalaxyAuthCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FString Appdata;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGalaxyAuthResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGalaxyAuthResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UGalaxyAuthCallbackProxy *GalaxyAuth( UObject *WorldContext, const FString &Appdata);

  virtual void Activate() override;

  virtual void OnGalaxyAuthDelegate(FModioResponse Response);
};