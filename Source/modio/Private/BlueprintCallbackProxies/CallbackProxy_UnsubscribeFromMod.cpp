// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_UnsubscribeFromMod.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_UnsubscribeFromMod::UCallbackProxy_UnsubscribeFromMod(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_UnsubscribeFromMod *UCallbackProxy_UnsubscribeFromMod::UnsubscribeFromMod( UObject *WorldContext, int32 ModId )
{
  UCallbackProxy_UnsubscribeFromMod *Proxy = NewObject<UCallbackProxy_UnsubscribeFromMod>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_UnsubscribeFromMod::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->UnsubscribeFromMod( this->ModId, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_UnsubscribeFromMod::OnUnsubscribeFromModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_UnsubscribeFromMod::OnUnsubscribeFromModDelegate(FModioResponse Response)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response);
  }
  else
  {
    OnFailure.Broadcast(Response);
  }
}