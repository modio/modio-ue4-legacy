// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AddModSketchfabLinksCallbackProxy.h"
#include "ModioSubsystem.h"

UAddModSketchfabLinksCallbackProxy::UAddModSketchfabLinksCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UAddModSketchfabLinksCallbackProxy *UAddModSketchfabLinksCallbackProxy::AddModSketchfabLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &SketchfabLinks )
{
  UAddModSketchfabLinksCallbackProxy *Proxy = NewObject<UAddModSketchfabLinksCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->SketchfabLinks = SketchfabLinks;
  return Proxy;
}

void UAddModSketchfabLinksCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->AddModSketchfabLinks( this->ModId, this->SketchfabLinks, FModioGenericDelegate::CreateUObject( this, &UAddModSketchfabLinksCallbackProxy::OnAddModSketchfabLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UAddModSketchfabLinksCallbackProxy::OnAddModSketchfabLinksDelegate(FModioResponse Response)
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