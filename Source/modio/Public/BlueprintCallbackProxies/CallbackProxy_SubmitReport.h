// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Enums/ModioReportType.h"
#include "Enums/ModioResourceType.h"
#include "CallbackProxy_SubmitReport.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FSubmitReportResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_SubmitReport : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  TEnumAsByte<EModioResourceType> Resource;
  int32 Id;
  TEnumAsByte<EModioReportType> Report;
  FString Name;
  FString Summary;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FSubmitReportResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FSubmitReportResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_SubmitReport *SubmitReport( UObject *WorldContext, TEnumAsByte<EModioResourceType> Resource, int32 Id, TEnumAsByte<EModioReportType> Report, const FString &Name, const FString &Summary);

  virtual void Activate() override;

  virtual void OnSubmitReportDelegate(FModioResponse Response);
};