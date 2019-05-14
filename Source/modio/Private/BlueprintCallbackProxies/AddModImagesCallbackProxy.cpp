// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AddModImagesCallbackProxy.h"
#include "ModioSubsystem.h"

UAddModImagesCallbackProxy::UAddModImagesCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UAddModImagesCallbackProxy *UAddModImagesCallbackProxy::AddModImages( UObject *WorldContext, int32 ModId, const TArray<FString> &ImagePaths )
{
  UAddModImagesCallbackProxy *Proxy = NewObject<UAddModImagesCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->ImagePaths = ImagePaths;
  return Proxy;
}

void UAddModImagesCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->AddModImages( this->ModId, this->ImagePaths, FModioGenericDelegate::CreateUObject( this, &UAddModImagesCallbackProxy::OnAddModImagesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UAddModImagesCallbackProxy::OnAddModImagesDelegate(FModioResponse Response)
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