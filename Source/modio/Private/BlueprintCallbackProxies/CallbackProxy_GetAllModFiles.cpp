// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAllModFiles.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAllModfiles::UCallbackProxy_GetAllModfiles(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAllModfiles* UCallbackProxy_GetAllModfiles::GetAllModfiles(UObject* WorldContext, int32 ModId)
{
  UCallbackProxy_GetAllModfiles* Proxy = NewObject<UCallbackProxy_GetAllModfiles>();
  Proxy->SetFlags(RF_StrongRefOnFrame);

  Proxy->ModId = ModId; 
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAllModfiles::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
  FModioSubsystemPtr Modio = FModioSubsystem::Get(World);
  if (Modio.IsValid())
  {
	Modio->GetAllModfiles(this->ModId, FModioModfileArrayDelegate::CreateUObject(this, &UCallbackProxy_GetAllModfiles::OnGetAllModfilesDelegate));
  }
  else
  {
	// @todonow: Make something more pretty than this
	FModioResponse Response;
	TArray<FModioModfile> Mods;
	OnFailure.Broadcast(Response, Mods);
  }
}

void UCallbackProxy_GetAllModfiles::OnGetAllModfilesDelegate(FModioResponse Response, const TArray<FModioModfile>& Modfiles)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
	OnSuccess.Broadcast(Response, Modfiles);
  }
  else
  {
	OnFailure.Broadcast(Response, Modfiles);
  }
}