// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DownloadSubscribedModfiles.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DownloadSubscribedModfiles::UCallbackProxy_DownloadSubscribedModfiles(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DownloadSubscribedModfiles *UCallbackProxy_DownloadSubscribedModfiles::DownloadSubscribedModfiles( UObject *WorldContext, bool UninstallUnsubscribed )
{
  UCallbackProxy_DownloadSubscribedModfiles *Proxy = NewObject<UCallbackProxy_DownloadSubscribedModfiles>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->UninstallUnsubscribed = UninstallUnsubscribed;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_DownloadSubscribedModfiles::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DownloadSubscribedModfiles( UninstallUnsubscribed, FModioBooleanDelegate::CreateUObject( this, &UCallbackProxy_DownloadSubscribedModfiles::OnDownloadSubscribedModfilesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response, false );
  }
}

void UCallbackProxy_DownloadSubscribedModfiles::OnDownloadSubscribedModfilesDelegate(FModioResponse Response, bool ModsAreUpdated)
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