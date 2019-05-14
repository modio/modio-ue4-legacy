// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "DeleteModYoutubeLinksCallbackProxy.h"
#include "ModioSubsystem.h"

UDeleteModYoutubeLinksCallbackProxy::UDeleteModYoutubeLinksCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UDeleteModYoutubeLinksCallbackProxy *UDeleteModYoutubeLinksCallbackProxy::DeleteModYoutubeLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &YoutubeLinks )
{
  UDeleteModYoutubeLinksCallbackProxy *Proxy = NewObject<UDeleteModYoutubeLinksCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->YoutubeLinks = YoutubeLinks;
  return Proxy;
}

void UDeleteModYoutubeLinksCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->DeleteModYoutubeLinks( this->ModId, this->YoutubeLinks, FModioGenericDelegate::CreateUObject( this, &UDeleteModYoutubeLinksCallbackProxy::OnDeleteModYoutubeLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UDeleteModYoutubeLinksCallbackProxy::OnDeleteModYoutubeLinksDelegate(FModioResponse Response)
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