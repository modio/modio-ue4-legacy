// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DeleteModYoutubeLinks.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DeleteModYoutubeLinks::UCallbackProxy_DeleteModYoutubeLinks(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DeleteModYoutubeLinks *UCallbackProxy_DeleteModYoutubeLinks::DeleteModYoutubeLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &YoutubeLinks )
{
  UCallbackProxy_DeleteModYoutubeLinks *Proxy = NewObject<UCallbackProxy_DeleteModYoutubeLinks>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->YoutubeLinks = YoutubeLinks;
  return Proxy;
}

void UCallbackProxy_DeleteModYoutubeLinks::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DeleteModYoutubeLinks( this->ModId, this->YoutubeLinks, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_DeleteModYoutubeLinks::OnDeleteModYoutubeLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_DeleteModYoutubeLinks::OnDeleteModYoutubeLinksDelegate(FModioResponse Response)
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