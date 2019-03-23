// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioUser.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "GetAuthenticatedUserCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAuthenticatedUserResult,
    FModioResponse,
    response,
    FModioUser,
    user);

UCLASS()
class MODIO_API UGetAuthenticatedUserCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  UPROPERTY(BlueprintAssignable)
  FGetAuthenticatedUserResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAuthenticatedUserResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UGetAuthenticatedUserCallbackProxy *GetAuthenticatedUser();

  virtual void Activate() override;

  virtual void OnGetAuthenticatedUserDelegate(FModioResponse Response, FModioUser User);
};