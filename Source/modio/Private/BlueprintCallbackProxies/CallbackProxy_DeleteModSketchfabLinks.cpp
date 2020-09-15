// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DeleteModSketchfabLinks.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DeleteModSketchfabLinks::UCallbackProxy_DeleteModSketchfabLinks(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DeleteModSketchfabLinks *UCallbackProxy_DeleteModSketchfabLinks::DeleteModSketchfabLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &SketchfabLinks )
{
  UCallbackProxy_DeleteModSketchfabLinks *Proxy = NewObject<UCallbackProxy_DeleteModSketchfabLinks>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->SketchfabLinks = SketchfabLinks;
  return Proxy;
}

void UCallbackProxy_DeleteModSketchfabLinks::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DeleteModSketchfabLinks( this->ModId, this->SketchfabLinks, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_DeleteModSketchfabLinks::OnDeleteModSketchfabLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_DeleteModSketchfabLinks::OnDeleteModSketchfabLinksDelegate(FModioResponse Response)
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