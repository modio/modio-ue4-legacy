// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "CallbackProxy_SetModUploadListener.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

UCallbackProxy_SetModUploadListener::UCallbackProxy_SetModUploadListener(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SetModUploadListener *UCallbackProxy_SetModUploadListener::SetModUploadListener(UObject *WorldContext)
{
  UCallbackProxy_SetModUploadListener *Proxy = NewObject<UCallbackProxy_SetModUploadListener>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_SetModUploadListener::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SetModUploadListener( FModioOnModUploadDelegate::CreateUObject( this, &UCallbackProxy_SetModUploadListener::OnModUploadDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    OnFailure.Broadcast( 0, 0 );
  }
}

void UCallbackProxy_SetModUploadListener::OnModUploadDelegate(int32 ResponseCode, int32 ModId)
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