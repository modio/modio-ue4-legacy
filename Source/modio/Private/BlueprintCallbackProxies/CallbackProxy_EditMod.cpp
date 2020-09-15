// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_EditMod.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_EditMod::UCallbackProxy_EditMod(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_EditMod *UCallbackProxy_EditMod::EditMod(UObject *WorldContext, int32 ModId, FModioModEditor ModEditor)
{
  UCallbackProxy_EditMod *Proxy = NewObject<UCallbackProxy_EditMod>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->ModEditor = ModEditor;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_EditMod::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->EditMod( this->ModId, this->ModEditor, FModioModDelegate::CreateUObject( this, &UCallbackProxy_EditMod::OnEditModDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioMod Mod;
    OnFailure.Broadcast( Response, Mod );
  }
}

void UCallbackProxy_EditMod::OnEditModDelegate(FModioResponse Response, FModioMod Mod)
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