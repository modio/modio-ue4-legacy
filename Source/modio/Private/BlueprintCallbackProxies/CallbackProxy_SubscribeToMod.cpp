// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_SubscribeToMod.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_SubscribeToMod::UCallbackProxy_SubscribeToMod(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SubscribeToMod *UCallbackProxy_SubscribeToMod::SubscribeToMod(UObject *WorldContext, int32 ModId)
{
  UCallbackProxy_SubscribeToMod *Proxy = NewObject<UCallbackProxy_SubscribeToMod>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_SubscribeToMod::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SubscribeToMod( this->ModId, FModioModDelegate::CreateUObject( this, &UCallbackProxy_SubscribeToMod::OnSubscribeToModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void UCallbackProxy_SubscribeToMod::OnSubscribeToModDelegate(FModioResponse Response, FModioMod Mod)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Mod);
  }
  else
  {
    OnFailure.Broadcast(Response, Mod);
  }
}