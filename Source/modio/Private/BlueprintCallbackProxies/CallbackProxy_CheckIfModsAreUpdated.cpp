// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_CheckIfModsAreUpdated.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_CheckIfModsAreUpdated::UCallbackProxy_CheckIfModsAreUpdated(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_CheckIfModsAreUpdated *UCallbackProxy_CheckIfModsAreUpdated::CheckIfModsAreUpdated( UObject *WorldContext, const TArray<int32> &ModIds )
{
  UCallbackProxy_CheckIfModsAreUpdated *Proxy = NewObject<UCallbackProxy_CheckIfModsAreUpdated>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModIds = ModIds;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_CheckIfModsAreUpdated::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->CheckIfModsAreUpdated( ModIds, FModioBooleanDelegate::CreateUObject( this, &UCallbackProxy_CheckIfModsAreUpdated::OnCheckIfModsAreUpdatedDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response, false );
  }
}

void UCallbackProxy_CheckIfModsAreUpdated::OnCheckIfModsAreUpdatedDelegate(FModioResponse Response, bool ModsAreUpdated)
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