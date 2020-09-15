// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_AddModImages.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FAddModImagesResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_AddModImages : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<FString> ImagePaths;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FAddModImagesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModImagesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_AddModImages *AddModImages( UObject *WorldContext, int32 ModId, const TArray<FString> &ImagePaths);

  virtual void Activate() override;

  virtual void OnAddModImagesDelegate(FModioResponse Response);
};