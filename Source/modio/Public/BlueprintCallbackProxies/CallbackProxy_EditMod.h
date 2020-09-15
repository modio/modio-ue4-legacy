// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Customizables/ModioModEditor.h"
#include "Enums/ModioMaturityOption.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_EditMod.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FEditModResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UCallbackProxy_EditMod : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioModEditor ModEditor;
  int32 ModId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FEditModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEditModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_EditMod *EditMod(UObject *WorldContext, int32 ModId, FModioModEditor ModEditor);

  virtual void Activate() override;

  virtual void OnEditModDelegate(FModioResponse Response, FModioMod Mod);
};