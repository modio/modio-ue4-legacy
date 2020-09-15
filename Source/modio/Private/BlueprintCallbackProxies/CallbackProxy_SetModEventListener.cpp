// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_SetModEventListener.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_SetModEventListener::UCallbackProxy_SetModEventListener(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SetModEventListener *UCallbackProxy_SetModEventListener::SetModEventListener(UObject *WorldContext)
{
  UCallbackProxy_SetModEventListener *Proxy = NewObject<UCallbackProxy_SetModEventListener>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_SetModEventListener::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SetModEventListener( FModioModEventArrayDelegate::CreateUObject( this, &UCallbackProxy_SetModEventListener::OnModEventDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioModEvent> ModEvents;
    OnFailure.Broadcast( Response, ModEvents );
  }
}

void UCallbackProxy_SetModEventListener::OnModEventDelegate(FModioResponse Response, const TArray<FModioModEvent> &ModEvents)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, ModEvents);
  }
  else
  {
    OnFailure.Broadcast(Response, ModEvents);
  }
}