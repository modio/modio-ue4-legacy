// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAllMetadataKVP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAllMetadataKVPResult,
    FModioResponse,
    Response,
    const TArray<FModioMetadataKVP> &,
    MetadataKVP);

UCLASS()
class MODIO_API UCallbackProxy_GetAllMetadataKVP : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetAllMetadataKVPResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllMetadataKVPResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetAllMetadataKVP *GetAllMetadataKVP( UObject *WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnGetAllMetadataKVPDelegate(FModioResponse Response, const TArray<FModioMetadataKVP> &MetadataKVP);
};