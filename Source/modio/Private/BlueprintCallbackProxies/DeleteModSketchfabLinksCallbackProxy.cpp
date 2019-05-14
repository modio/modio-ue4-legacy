// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "DeleteModSketchfabLinksCallbackProxy.h"
#include "ModioSubsystem.h"

UDeleteModSketchfabLinksCallbackProxy::UDeleteModSketchfabLinksCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UDeleteModSketchfabLinksCallbackProxy *UDeleteModSketchfabLinksCallbackProxy::DeleteModSketchfabLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &SketchfabLinks )
{
  UDeleteModSketchfabLinksCallbackProxy *Proxy = NewObject<UDeleteModSketchfabLinksCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->SketchfabLinks = SketchfabLinks;
  return Proxy;
}

void UDeleteModSketchfabLinksCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->DeleteModSketchfabLinks( this->ModId, this->SketchfabLinks, FModioGenericDelegate::CreateUObject( this, &UDeleteModSketchfabLinksCallbackProxy::OnDeleteModSketchfabLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UDeleteModSketchfabLinksCallbackProxy::OnDeleteModSketchfabLinksDelegate(FModioResponse Response)
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