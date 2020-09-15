// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_AddModTags.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FAddModTagsResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_AddModTags : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<FString> Tags;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FAddModTagsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FAddModTagsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_AddModTags *AddModTags( UObject *WorldContext, int32 ModId, const TArray<FString> &Tags);

  virtual void Activate() override;

  virtual void OnAddModTagsDelegate(FModioResponse Response);
};