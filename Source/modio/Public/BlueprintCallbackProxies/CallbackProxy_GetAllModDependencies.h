// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAllModDependencies.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAllModDependenciesResult,
    FModioResponse,
    Response,
    const TArray<FModioModDependency> &,
    ModDependencies);

UCLASS()
class MODIO_API UCallbackProxy_GetAllModDependencies : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetAllModDependenciesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllModDependenciesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetAllModDependencies *GetAllModDependencies( UObject *WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnGetAllModDependenciesDelegate(FModioResponse Response, const TArray<FModioModDependency> &ModDependencies);
};