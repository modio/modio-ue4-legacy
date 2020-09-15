// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetMod.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetMod::UCallbackProxy_GetMod(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetMod *UCallbackProxy_GetMod::GetMod(UObject *WorldContext, int32 ModId)
{
	UCallbackProxy_GetMod *Proxy = NewObject<UCallbackProxy_GetMod>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetMod::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetMod( this->ModId, FModioModDelegate::CreateUObject( this, &UCallbackProxy_GetMod::OnGetModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
	FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void UCallbackProxy_GetMod::OnGetModDelegate(FModioResponse Response, FModioMod Mod)
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