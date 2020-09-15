// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModTag.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAllModTags.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAllModTagsResult,
    FModioResponse,
    Response,
    const TArray<FModioModTag> &,
    ModTags);

UCLASS()
class MODIO_API UCallbackProxy_GetAllModTags : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetAllModTagsResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllModTagsResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetAllModTags *GetAllModTags( UObject *WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnGetAllModTagsDelegate(FModioResponse Response, const TArray<FModioModTag> &Tags);
};