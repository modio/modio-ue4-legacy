// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_SetModfileUploadListener.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_SetModfileUploadListener::UCallbackProxy_SetModfileUploadListener(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SetModfileUploadListener *UCallbackProxy_SetModfileUploadListener::SetModfileUploadListener(UObject *WorldContext)
{
  UCallbackProxy_SetModfileUploadListener *Proxy = NewObject<UCallbackProxy_SetModfileUploadListener>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_SetModfileUploadListener::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SetModfileUploadListener( FModioListenerDelegate::CreateUObject( this, &UCallbackProxy_SetModfileUploadListener::OnModUploadDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    OnFailure.Broadcast( 0, 0 );
  }
}

void UCallbackProxy_SetModfileUploadListener::OnModUploadDelegate(int32 ResponseCode, int32 ModId)
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