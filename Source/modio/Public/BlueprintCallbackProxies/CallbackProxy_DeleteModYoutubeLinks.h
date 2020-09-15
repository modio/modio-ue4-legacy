// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioResponse.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "CallbackProxy_DeleteModYoutubeLinks.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FDeleteModYoutubeLinksResult,
FModioResponse,
response );

UCLASS()
class MODIO_API UCallbackProxy_DeleteModYoutubeLinks : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  int32 ModId;
  TArray<FString> YoutubeLinks;

  // The world context object in which this call is taking place
  UPROPERTY()
  UObject* WorldContextObject;

  UPROPERTY(BlueprintAssignable)
  FDeleteModYoutubeLinksResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FDeleteModYoutubeLinksResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true", DefaultToSelf="WorldContext"))
  static UCallbackProxy_DeleteModYoutubeLinks *DeleteModYoutubeLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &YoutubeLinks);

  virtual void Activate() override;

  virtual void OnDeleteModYoutubeLinksDelegate(FModioResponse Response);
};