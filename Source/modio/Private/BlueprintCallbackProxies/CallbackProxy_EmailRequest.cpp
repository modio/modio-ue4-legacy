// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_EmailRequest.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_EmailRequest::UCallbackProxy_EmailRequest(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_EmailRequest *UCallbackProxy_EmailRequest::EmailRequest( UObject *WorldContext, const FString& Email )
{
  UCallbackProxy_EmailRequest *Proxy = NewObject<UCallbackProxy_EmailRequest>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Email = Email;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_EmailRequest::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->EmailRequest( Email, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_EmailRequest::OnEmailRequestDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_EmailRequest::OnEmailRequestDelegate(FModioResponse Response)
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