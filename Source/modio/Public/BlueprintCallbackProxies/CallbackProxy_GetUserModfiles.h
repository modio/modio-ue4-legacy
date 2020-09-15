// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModfile.h"
#include "Enums/ModioModSortType.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetUserModfiles.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetUserModfilesResult,
    FModioResponse,
    Response,
    const TArray<FModioModfile> &,
    Modfiles);

UCLASS()
class MODIO_API UCallbackProxy_GetUserModfiles : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 Limit;
  int32 Offset;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetUserModfilesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetUserModfilesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetUserModfiles *GetUserModfiles(UObject *WorldContext, int32 Limit, int32 Offset);

  virtual void Activate() override;

  virtual void OnGetUserModfilesDelegate(FModioResponse Response, const TArray<FModioModfile> &Modfiles);
};