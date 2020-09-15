// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddModImages.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddModImages::UCallbackProxy_AddModImages(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddModImages *UCallbackProxy_AddModImages::AddModImages( UObject *WorldContext, int32 ModId, const TArray<FString> &ImagePaths )
{
  UCallbackProxy_AddModImages *Proxy = NewObject<UCallbackProxy_AddModImages>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->ImagePaths = ImagePaths;
  return Proxy;
}

void UCallbackProxy_AddModImages::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModImages( this->ModId, this->ImagePaths, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddModImages::OnAddModImagesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddModImages::OnAddModImagesDelegate(FModioResponse Response)
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