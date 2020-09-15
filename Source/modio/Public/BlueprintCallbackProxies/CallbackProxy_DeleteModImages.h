// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DeleteModImages.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FDeleteModImagesResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_DeleteModImages : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<FString> ImagePaths;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDeleteModImagesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDeleteModImagesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DeleteModImages *DeleteModImages( UObject *WorldContext, int32 ModId, const TArray<FString> &ImagePaths);

  virtual void Activate() override;

  virtual void OnDeleteModImagesDelegate(FModioResponse Response);
};