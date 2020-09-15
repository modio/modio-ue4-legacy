// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DeleteModImages.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DeleteModImages::UCallbackProxy_DeleteModImages(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DeleteModImages *UCallbackProxy_DeleteModImages::DeleteModImages( UObject *WorldContext, int32 ModId, const TArray<FString> &ImagePaths )
{
  UCallbackProxy_DeleteModImages *Proxy = NewObject<UCallbackProxy_DeleteModImages>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->ImagePaths = ImagePaths;
  return Proxy;
}

void UCallbackProxy_DeleteModImages::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DeleteModImages( this->ModId, this->ImagePaths, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_DeleteModImages::OnDeleteModImagesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_DeleteModImages::OnDeleteModImagesDelegate(FModioResponse Response)
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