// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddModDependencies.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddModDependencies::UCallbackProxy_AddModDependencies(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddModDependencies *UCallbackProxy_AddModDependencies::AddModDependencies( UObject *WorldContext, int32 ModId, const TArray<int32> &Dependencies )
{
  UCallbackProxy_AddModDependencies *Proxy = NewObject<UCallbackProxy_AddModDependencies>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->Dependencies = Dependencies;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_AddModDependencies::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModDependencies( ModId, Dependencies, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddModDependencies::OnAddModDependenciesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddModDependencies::OnAddModDependenciesDelegate(FModioResponse Response)
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