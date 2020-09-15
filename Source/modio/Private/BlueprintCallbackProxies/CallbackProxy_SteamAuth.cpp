// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_SteamAuth.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_SteamAuth::UCallbackProxy_SteamAuth(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SteamAuth *UCallbackProxy_SteamAuth::SteamAuth( UObject *WorldContext, const FString& Base64Ticket )
{
  UCallbackProxy_SteamAuth *Proxy = NewObject<UCallbackProxy_SteamAuth>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Base64Ticket = Base64Ticket;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_SteamAuth::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SteamAuth( Base64Ticket, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_SteamAuth::OnSteamAuthDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_SteamAuth::OnSteamAuthDelegate(FModioResponse Response)
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