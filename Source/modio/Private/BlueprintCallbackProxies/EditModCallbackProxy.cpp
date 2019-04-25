// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "EditModCallbackProxy.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

UEditModCallbackProxy::UEditModCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UEditModCallbackProxy *UEditModCallbackProxy::EditMod(UObject *WorldContext, int32 ModId, FModioModEditor ModEditor)
{
  UEditModCallbackProxy *Proxy = NewObject<UEditModCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->ModEditor = ModEditor;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UEditModCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->EditMod( this->ModId, this->ModEditor, FModioModDelegate::CreateUObject( this, &UEditModCallbackProxy::OnEditModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void UEditModCallbackProxy::OnEditModDelegate(FModioResponse Response, FModioMod Mod)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Mod);
  }
  else
  {
    OnFailure.Broadcast(Response, Mod);
  }
}