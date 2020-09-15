// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddModSketchfabLinks.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddModSketchfabLinks::UCallbackProxy_AddModSketchfabLinks(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddModSketchfabLinks *UCallbackProxy_AddModSketchfabLinks::AddModSketchfabLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &SketchfabLinks )
{
  UCallbackProxy_AddModSketchfabLinks *Proxy = NewObject<UCallbackProxy_AddModSketchfabLinks>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->SketchfabLinks = SketchfabLinks;
  return Proxy;
}

void UCallbackProxy_AddModSketchfabLinks::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModSketchfabLinks( this->ModId, this->SketchfabLinks, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddModSketchfabLinks::OnAddModSketchfabLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddModSketchfabLinks::OnAddModSketchfabLinksDelegate(FModioResponse Response)
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