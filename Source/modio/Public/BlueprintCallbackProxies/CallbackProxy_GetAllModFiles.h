// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"
#include "Customizables/ModioFilterCreator.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModfile.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAllModFiles.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
FGetAllModfilesResult,
FModioResponse,
Response,
const TArray<FModioModfile>&,
Modfile);

UCLASS()
class MODIO_API UCallbackProxy_GetAllModfiles : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  UPROPERTY(BlueprintAssignable)
  FGetAllModfilesResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAllModfilesResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf = "WorldContext"))
  static UCallbackProxy_GetAllModfiles* GetAllModfiles(UObject* WorldContext, int32 ModId);

  virtual void Activate() override;

  virtual void OnGetAllModfilesDelegate(FModioResponse Response, const TArray<FModioModfile>& Modfiles);
private:
  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  int32 ModId;
};