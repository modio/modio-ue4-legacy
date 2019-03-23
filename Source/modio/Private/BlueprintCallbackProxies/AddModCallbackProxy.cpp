// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AddModCallbackProxy.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

UAddModCallbackProxy::UAddModCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UAddModCallbackProxy *UAddModCallbackProxy::AddMod(UObject *WorldContextObject, FModioModCreator ModCreator)
{
  UAddModCallbackProxy *Proxy = NewObject<UAddModCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModCreator = ModCreator;
  Proxy->WorldContextObject = WorldContextObject;
  return Proxy;
}

void UAddModCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->AddMod( this->ModCreator, FAddModDelegate::CreateUObject( this, &UAddModCallbackProxy::OnAddModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void UAddModCallbackProxy::OnAddModDelegate(FModioResponse Response, FModioMod Mod)
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