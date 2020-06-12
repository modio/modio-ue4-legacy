// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_UninstallUnavailableMods.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_UninstallUnavailableMods::UCallbackProxy_UninstallUnavailableMods(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_UninstallUnavailableMods *UCallbackProxy_UninstallUnavailableMods::UninstallUnavailableMods(UObject *WorldContext)
{
  UCallbackProxy_UninstallUnavailableMods *Proxy = NewObject<UCallbackProxy_UninstallUnavailableMods>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_UninstallUnavailableMods::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->UninstallUnavailableMods( FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_UninstallUnavailableMods::OnUninstallUnavailableModsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_UninstallUnavailableMods::OnUninstallUnavailableModsDelegate(FModioResponse Response)
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