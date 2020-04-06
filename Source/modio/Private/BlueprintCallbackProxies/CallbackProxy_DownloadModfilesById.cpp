// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DownloadModfilesById.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DownloadModfilesById::UCallbackProxy_DownloadModfilesById(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DownloadModfilesById *UCallbackProxy_DownloadModfilesById::DownloadModfilesById( UObject *WorldContext, const TArray<int32> &ModIds )
{
  UCallbackProxy_DownloadModfilesById *Proxy = NewObject<UCallbackProxy_DownloadModfilesById>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModIds = ModIds;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_DownloadModfilesById::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DownloadModfilesById( ModIds, FModioBooleanDelegate::CreateUObject( this, &UCallbackProxy_DownloadModfilesById::OnDownloadModfilesByIdDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response, false );
  }
}

void UCallbackProxy_DownloadModfilesById::OnDownloadModfilesByIdDelegate(FModioResponse Response, bool ModsAreUpdated)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, ModsAreUpdated);
  }
  else
  {
    OnFailure.Broadcast(Response, ModsAreUpdated);
  }
}