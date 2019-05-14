// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AddModLogoCallbackProxy.h"
#include "ModioSubsystem.h"

UAddModLogoCallbackProxy::UAddModLogoCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UAddModLogoCallbackProxy *UAddModLogoCallbackProxy::AddModLogo( UObject *WorldContext, int32 ModId, const FString& LogoPath )
{
  UAddModLogoCallbackProxy *Proxy = NewObject<UAddModLogoCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->LogoPath = LogoPath;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UAddModLogoCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->AddModLogo( ModId, LogoPath, FModioGenericDelegate::CreateUObject( this, &UAddModLogoCallbackProxy::OnAddModLogoDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UAddModLogoCallbackProxy::OnAddModLogoDelegate(FModioResponse Response)
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