// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_OculusAuth.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_OculusAuth::UCallbackProxy_OculusAuth(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_OculusAuth *UCallbackProxy_OculusAuth::OculusAuth( UObject *WorldContext, const FString& Nonce, FInt64 UserId, const FString& AccessToken, const FString& Email, int32 DateExpires )
{
  UCallbackProxy_OculusAuth *Proxy = NewObject<UCallbackProxy_OculusAuth>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Nonce = Nonce;
  Proxy->UserId = UserId;
  Proxy->AccessToken = AccessToken;
  Proxy->Email = Email;
  Proxy->DateExpires = DateExpires;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_OculusAuth::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->OculusAuth( Nonce, UserId, AccessToken, Email, DateExpires, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_OculusAuth::OnOculusAuthDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_OculusAuth::OnOculusAuthDelegate(FModioResponse Response)
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