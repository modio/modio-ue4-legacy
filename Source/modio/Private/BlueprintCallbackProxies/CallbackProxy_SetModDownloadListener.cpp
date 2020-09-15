// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_SetModDownloadListener.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_SetModDownloadListener::UCallbackProxy_SetModDownloadListener(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SetModDownloadListener *UCallbackProxy_SetModDownloadListener::SetModDownloadListener(UObject *WorldContext)
{
  UCallbackProxy_SetModDownloadListener *Proxy = NewObject<UCallbackProxy_SetModDownloadListener>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_SetModDownloadListener::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SetModDownloadListener( FModioListenerDelegate::CreateUObject( this, &UCallbackProxy_SetModDownloadListener::OnModDownloadDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    OnFailure.Broadcast( 0, 0 );
  }
}

void UCallbackProxy_SetModDownloadListener::OnModDownloadDelegate(int32 ResponseCode, int32 ModId)
{
  if (ResponseCode >= 200 && ResponseCode < 300)
  {
    OnSuccess.Broadcast(ResponseCode, ModId);
  }
  else
  {
    OnFailure.Broadcast(ResponseCode, ModId);
  }
}