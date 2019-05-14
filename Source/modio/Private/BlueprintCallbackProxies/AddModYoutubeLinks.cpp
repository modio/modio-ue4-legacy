// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AddModYoutubeLinksCallbackProxy.h"
#include "ModioSubsystem.h"

UAddModYoutubeLinksCallbackProxy::UAddModYoutubeLinksCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UAddModYoutubeLinksCallbackProxy *UAddModYoutubeLinksCallbackProxy::AddModYoutubeLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &YoutubeLinks )
{
  UAddModYoutubeLinksCallbackProxy *Proxy = NewObject<UAddModYoutubeLinksCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->YoutubeLinks = YoutubeLinks;
  return Proxy;
}

void UAddModYoutubeLinksCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->AddModYoutubeLinks( this->ModId, this->YoutubeLinks, FModioGenericDelegate::CreateUObject( this, &UAddModYoutubeLinksCallbackProxy::OnAddModYoutubeLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UAddModYoutubeLinksCallbackProxy::OnAddModYoutubeLinksDelegate(FModioResponse Response)
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