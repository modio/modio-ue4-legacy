// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddModLogo.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddModLogo::UCallbackProxy_AddModLogo(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddModLogo *UCallbackProxy_AddModLogo::AddModLogo( UObject *WorldContext, int32 ModId, const FString& LogoPath )
{
  UCallbackProxy_AddModLogo *Proxy = NewObject<UCallbackProxy_AddModLogo>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->LogoPath = LogoPath;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_AddModLogo::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModLogo( ModId, LogoPath, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddModLogo::OnAddModLogoDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddModLogo::OnAddModLogoDelegate(FModioResponse Response)
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