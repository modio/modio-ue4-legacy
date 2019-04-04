// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "EmailRequestCallbackProxy.h"
#include "ModioSubsystem.h"

UEmailRequestCallbackProxy::UEmailRequestCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UEmailRequestCallbackProxy *UEmailRequestCallbackProxy::EmailRequest( UObject *WorldContextObject, const FString& Email )
{
  UEmailRequestCallbackProxy *Proxy = NewObject<UEmailRequestCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Email = Email;
  Proxy->WorldContextObject = WorldContextObject;
  return Proxy;
}

void UEmailRequestCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->EmailRequest( Email, FModioGenericDelegate::CreateUObject( this, &UEmailRequestCallbackProxy::OnEmailRequestDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UEmailRequestCallbackProxy::OnEmailRequestDelegate(FModioResponse Response)
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