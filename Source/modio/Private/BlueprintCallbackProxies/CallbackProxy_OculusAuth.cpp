// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_OculusAuth.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_OculusAuth::UCallbackProxy_OculusAuth(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_OculusAuth *UCallbackProxy_OculusAuth::OculusAuth( UObject *WorldContext, const FString& Nonce, const FString& OculusUserId, const FString& AccessToken, const FString& Email, const FString& Device, int32 DateExpires )
{
  UCallbackProxy_OculusAuth *Proxy = NewObject<UCallbackProxy_OculusAuth>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Nonce = Nonce;
  Proxy->OculusUserId = OculusUserId;
  Proxy->AccessToken = AccessToken;
  Proxy->Email = Email;
  Proxy->Device = Device;
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
    Modio->OculusAuth( Nonce, OculusUserId, AccessToken, Email, Device, DateExpires, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_OculusAuth::OnOculusAuthDelegate ) );
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