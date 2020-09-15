// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioResponse.h"
#include "Schemas/ModioUser.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_GetAuthenticatedUser.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAuthenticatedUserResult,
    FModioResponse,
    response,
    FModioUser,
    user);

UCLASS()
class MODIO_API UCallbackProxy_GetAuthenticatedUser : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FGetAuthenticatedUserResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAuthenticatedUserResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_GetAuthenticatedUser *GetAuthenticatedUser(UObject *WorldContext);

  virtual void Activate() override;

  virtual void OnGetAuthenticatedUserDelegate(FModioResponse Response, FModioUser User);
};