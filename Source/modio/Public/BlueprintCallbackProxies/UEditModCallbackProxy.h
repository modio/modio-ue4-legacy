// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Enums/EModioMaturityOption.h"
#include "Customizables/FModioModEditor.h"
#include "Schemas/FModioResponse.h"
#include "Schemas/FModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UEditModCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FEditModCheckResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UEditModCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioModEditor ModEditor;
  int32 ModId;

  UPROPERTY(BlueprintAssignable)
  FEditModCheckResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEditModCheckResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UEditModCallbackProxy *EditMod(int32 ModId, FModioModEditor ModEditor);

  virtual void Activate() override;

  void OnEditModDelegate(FModioResponse Response, FModioMod Mod);
};