// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_EmailExchange.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_EmailExchange::UCallbackProxy_EmailExchange(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_EmailExchange *UCallbackProxy_EmailExchange::EmailExchange( UObject *WorldContext, const FString& SecurityCode )
{
  UCallbackProxy_EmailExchange *Proxy = NewObject<UCallbackProxy_EmailExchange>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->SecurityCode = SecurityCode;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_EmailExchange::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->EmailExchange( SecurityCode, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_EmailExchange::OnEmailExchangeDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_EmailExchange::OnEmailExchangeDelegate(FModioResponse Response)
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