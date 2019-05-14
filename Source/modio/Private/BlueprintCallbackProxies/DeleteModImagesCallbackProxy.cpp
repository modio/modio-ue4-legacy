// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "DeleteModImagesCallbackProxy.h"
#include "ModioSubsystem.h"

UDeleteModImagesCallbackProxy::UDeleteModImagesCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UDeleteModImagesCallbackProxy *UDeleteModImagesCallbackProxy::DeleteModImages( UObject *WorldContext, int32 ModId, const TArray<FString> &ImagePaths )
{
  UDeleteModImagesCallbackProxy *Proxy = NewObject<UDeleteModImagesCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->ImagePaths = ImagePaths;
  return Proxy;
}

void UDeleteModImagesCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->DeleteModImages( this->ModId, this->ImagePaths, FModioGenericDelegate::CreateUObject( this, &UDeleteModImagesCallbackProxy::OnDeleteModImagesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UDeleteModImagesCallbackProxy::OnDeleteModImagesDelegate(FModioResponse Response)
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