// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DownloadModfilesById.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
FDownloadModfilesByIdResult,
FModioResponse,
response,
bool,
mods_are_updated );

UCLASS()
class MODIO_API UCallbackProxy_DownloadModfilesById : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TArray<int32> ModIds;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDownloadModfilesByIdResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDownloadModfilesByIdResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DownloadModfilesById *DownloadModfilesById( UObject *WorldContext, const TArray<int32> &ModIds);

  virtual void Activate() override;

  virtual void OnDownloadModfilesByIdDelegate(FModioResponse Response, bool ModsAreUpdated);
};