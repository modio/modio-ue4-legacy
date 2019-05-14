// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "AddModSketchfabLinksCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FAddModSketchfabLinksResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UAddModSketchfabLinksCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<FString> SketchfabLinks;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FAddModSketchfabLinksResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModSketchfabLinksResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UAddModSketchfabLinksCallbackProxy *AddModSketchfabLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &SketchfabLinks);

  virtual void Activate() override;

  virtual void OnAddModSketchfabLinksDelegate(FModioResponse Response);
};