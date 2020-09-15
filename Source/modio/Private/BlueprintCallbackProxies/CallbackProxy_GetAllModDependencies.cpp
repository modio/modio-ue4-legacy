// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAllModDependencies.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAllModDependencies::UCallbackProxy_GetAllModDependencies(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAllModDependencies *UCallbackProxy_GetAllModDependencies::GetAllModDependencies( UObject *WorldContext, int32 ModId )
{
  UCallbackProxy_GetAllModDependencies *Proxy = NewObject<UCallbackProxy_GetAllModDependencies>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAllModDependencies::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetAllModDependencies( ModId, FModioModDependencyArrayDelegate::CreateUObject( this, &UCallbackProxy_GetAllModDependencies::OnGetAllModDependenciesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioModDependency> Dependencies;
    OnFailure.Broadcast( Response, Dependencies );
  }
}

void UCallbackProxy_GetAllModDependencies::OnGetAllModDependenciesDelegate(FModioResponse Response, const TArray<FModioModDependency> &Dependencies)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Dependencies);
  }
  else
  {
    OnFailure.Broadcast(Response, Dependencies);
  }
}