// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"
#include "Customizables/ModioFilterCreator.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_UninstallUnavailableMods.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FUninstallUnavailableModsResult,
    FModioResponse,
    Response);

UCLASS()
class MODIO_API UCallbackProxy_UninstallUnavailableMods : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;
  
  UPROPERTY(BlueprintAssignable)
  FUninstallUnavailableModsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FUninstallUnavailableModsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_UninstallUnavailableMods *UninstallUnavailableMods(UObject *WorldContext);

  virtual void Activate() override;

  virtual void OnUninstallUnavailableModsDelegate(FModioResponse Response);
};