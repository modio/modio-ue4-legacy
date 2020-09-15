// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DeleteModDependencies.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DeleteModDependencies::UCallbackProxy_DeleteModDependencies(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DeleteModDependencies *UCallbackProxy_DeleteModDependencies::DeleteModDependencies( UObject *WorldContext, int32 ModId, const TArray<int32> &Dependencies )
{
  UCallbackProxy_DeleteModDependencies *Proxy = NewObject<UCallbackProxy_DeleteModDependencies>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->Dependencies = Dependencies;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_DeleteModDependencies::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DeleteModDependencies( ModId, Dependencies, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_DeleteModDependencies::OnDeleteModDependenciesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_DeleteModDependencies::OnDeleteModDependenciesDelegate(FModioResponse Response)
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