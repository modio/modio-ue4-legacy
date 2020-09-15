// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DeleteModSketchfabLinks.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FDeleteModSketchfabLinksResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_DeleteModSketchfabLinks : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<FString> SketchfabLinks;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDeleteModSketchfabLinksResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDeleteModSketchfabLinksResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DeleteModSketchfabLinks *DeleteModSketchfabLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &SketchfabLinks);

  virtual void Activate() override;

  virtual void OnDeleteModSketchfabLinksDelegate(FModioResponse Response);
};