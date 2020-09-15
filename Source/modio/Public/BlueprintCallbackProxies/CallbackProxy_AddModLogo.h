// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_AddModLogo.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FAddModLogoResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_AddModLogo : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  FString LogoPath;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FAddModLogoResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModLogoResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_AddModLogo *AddModLogo( UObject *WorldContext, int32 ModId, const FString &LogoPath);

  virtual void Activate() override;

  virtual void OnAddModLogoDelegate(FModioResponse Response);
};