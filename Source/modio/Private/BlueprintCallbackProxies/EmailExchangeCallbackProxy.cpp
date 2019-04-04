// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "EmailExchangeCallbackProxy.h"
#include "ModioSubsystem.h"

UEmailExchangeCallbackProxy::UEmailExchangeCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UEmailExchangeCallbackProxy *UEmailExchangeCallbackProxy::EmailExchange( UObject *WorldContext, const FString& SecurityCode )
{
  UEmailExchangeCallbackProxy *Proxy = NewObject<UEmailExchangeCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->SecurityCode = SecurityCode;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UEmailExchangeCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->EmailExchange( SecurityCode, FModioGenericDelegate::CreateUObject( this, &UEmailExchangeCallbackProxy::OnEmailExchangeDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UEmailExchangeCallbackProxy::OnEmailExchangeDelegate(FModioResponse Response)
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