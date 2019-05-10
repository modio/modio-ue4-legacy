// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "GalaxyAuthCallbackProxy.h"
#include "ModioSubsystem.h"

UGalaxyAuthCallbackProxy::UGalaxyAuthCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGalaxyAuthCallbackProxy *UGalaxyAuthCallbackProxy::GalaxyAuth( UObject *WorldContext, const FString& Appdata )
{
  UGalaxyAuthCallbackProxy *Proxy = NewObject<UGalaxyAuthCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Appdata = Appdata;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UGalaxyAuthCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->GalaxyAuth( Appdata, FModioGenericDelegate::CreateUObject( this, &UGalaxyAuthCallbackProxy::OnGalaxyAuthDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UGalaxyAuthCallbackProxy::OnGalaxyAuthDelegate(FModioResponse Response)
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