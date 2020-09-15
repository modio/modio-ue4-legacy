// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddMod.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddMod::UCallbackProxy_AddMod(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddMod *UCallbackProxy_AddMod::AddMod(UObject *WorldContext, FModioModCreator ModCreator)
{
  UCallbackProxy_AddMod *Proxy = NewObject<UCallbackProxy_AddMod>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModCreator = ModCreator;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_AddMod::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddMod( this->ModCreator, FModioModDelegate::CreateUObject( this, &UCallbackProxy_AddMod::OnAddModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void UCallbackProxy_AddMod::OnAddModDelegate(FModioResponse Response, FModioMod Mod)
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