// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GalaxyAuth.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GalaxyAuth::UCallbackProxy_GalaxyAuth(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GalaxyAuth *UCallbackProxy_GalaxyAuth::GalaxyAuth( UObject *WorldContext, const FString& Appdata )
{
  UCallbackProxy_GalaxyAuth *Proxy = NewObject<UCallbackProxy_GalaxyAuth>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Appdata = Appdata;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GalaxyAuth::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GalaxyAuth( Appdata, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_GalaxyAuth::OnGalaxyAuthDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_GalaxyAuth::OnGalaxyAuthDelegate(FModioResponse Response)
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