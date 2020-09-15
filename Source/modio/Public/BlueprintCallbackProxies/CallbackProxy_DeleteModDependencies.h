// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DeleteModDependencies.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FDeleteModDependenciesResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_DeleteModDependencies : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<int32> Dependencies;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDeleteModDependenciesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDeleteModDependenciesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DeleteModDependencies *DeleteModDependencies( UObject *WorldContext, int32 ModId, const TArray<int32> &Dependencies);

  virtual void Activate() override;

  virtual void OnDeleteModDependenciesDelegate(FModioResponse Response);
};