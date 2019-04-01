// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UnsubscribeFromModCallbackProxy.h"
#include "ModioSubsystem.h"

UUnsubscribeFromModCallbackProxy::UUnsubscribeFromModCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UUnsubscribeFromModCallbackProxy *UUnsubscribeFromModCallbackProxy::UnsubscribeFromMod( UObject *WorldContextObject, int32 ModId )
{
  UUnsubscribeFromModCallbackProxy *Proxy = NewObject<UUnsubscribeFromModCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContextObject;
  return Proxy;
}

void UUnsubscribeFromModCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->UnsubscribeFromMod( this->ModId, FModioGenericDelegate::CreateUObject( this, &UUnsubscribeFromModCallbackProxy::OnUnsubscribeFromModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UUnsubscribeFromModCallbackProxy::OnUnsubscribeFromModDelegate(FModioResponse Response)
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