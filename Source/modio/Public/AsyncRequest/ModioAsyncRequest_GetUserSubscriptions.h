#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "ModioAsyncRequest_GetUserSubscriptions.generated.h"

/**
* Callback returning the mods that the current user has subscribed
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/
DECLARE_DELEGATE_TwoParams( FGetUserSubscriptionsDelegate, FModioResponse, const TArray<FModioMod> & );

class FModioAsyncRequest_GetUserSubscriptions : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetUserSubscriptions( FModioSubsystem *Modio, FGetUserSubscriptionsDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize);

private:
  FGetUserSubscriptionsDelegate ResponseDelegate;
};

// @todo: find a better workarround to create the generate.h in order to setup the delegate 
UCLASS()
class MODIO_API UGetUserSubscriptionsDelegateGenerator : public UObject
{
  GENERATED_BODY()
};