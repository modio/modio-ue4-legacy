// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DeleteMetadataKVP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FDeleteMetadataKVPResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_DeleteMetadataKVP : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TMap<FString, FString> MetadataKVP;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDeleteMetadataKVPResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDeleteMetadataKVPResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DeleteMetadataKVP *DeleteMetadataKVP( UObject *WorldContext, int32 ModId, const TMap<FString, FString> &MetadataKVP);

  virtual void Activate() override;

  virtual void OnDeleteMetadataKVPDelegate(FModioResponse Response);
};