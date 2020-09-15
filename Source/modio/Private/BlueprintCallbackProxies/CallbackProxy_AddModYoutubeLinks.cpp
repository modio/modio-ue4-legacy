// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddModYoutubeLinks.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddModYoutubeLinks::UCallbackProxy_AddModYoutubeLinks(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddModYoutubeLinks *UCallbackProxy_AddModYoutubeLinks::AddModYoutubeLinks( UObject *WorldContext, int32 ModId, const TArray<FString> &YoutubeLinks )
{
  UCallbackProxy_AddModYoutubeLinks *Proxy = NewObject<UCallbackProxy_AddModYoutubeLinks>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->ModId = ModId;
  Proxy->YoutubeLinks = YoutubeLinks;
  return Proxy;
}

void UCallbackProxy_AddModYoutubeLinks::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModYoutubeLinks( this->ModId, this->YoutubeLinks, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddModYoutubeLinks::OnAddModYoutubeLinksDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddModYoutubeLinks::OnAddModYoutubeLinksDelegate(FModioResponse Response)
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