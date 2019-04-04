// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "SubscribeToModCallbackProxy.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

USubscribeToModCallbackProxy::USubscribeToModCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

USubscribeToModCallbackProxy *USubscribeToModCallbackProxy::SubscribeToMod(UObject *WorldContext, int32 ModId)
{
  USubscribeToModCallbackProxy *Proxy = NewObject<USubscribeToModCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void USubscribeToModCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->SubscribeToMod( this->ModId, FModioModDelegate::CreateUObject( this, &USubscribeToModCallbackProxy::OnSubscribeToModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void USubscribeToModCallbackProxy::OnSubscribeToModDelegate(FModioResponse Response, FModioMod Mod)
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