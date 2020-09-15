// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioGame.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetGame.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
  FGetGameResult,
  FModioResponse,
  Response,
  FModioGame,
  Game);

UCLASS()
class MODIO_API UCallbackProxy_GetGame : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  UPROPERTY(BlueprintAssignable)
  FGetGameResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetGameResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf = "WorldContext"))
  static UCallbackProxy_GetGame* GetGame(UObject* WorldContext, int32 GameId);

  virtual void Activate() override;
private:
  virtual void OnGetGameDelegate(FModioResponse Response, FModioGame Game);

  int32 GameId;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;
};