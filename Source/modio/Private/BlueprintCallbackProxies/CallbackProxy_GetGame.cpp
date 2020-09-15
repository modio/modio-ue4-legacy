// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetGame.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetGame::UCallbackProxy_GetGame(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

UCallbackProxy_GetGame* UCallbackProxy_GetGame::GetGame(UObject* WorldContext, int32 GameId)
{
  UCallbackProxy_GetGame* Proxy = NewObject<UCallbackProxy_GetGame>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->GameId = GameId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetGame::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
  FModioSubsystemPtr Modio = FModioSubsystem::Get(World);
  if (Modio.IsValid())
  {
    Modio->GetGame(this->GameId, FModioGameDelegate::CreateUObject(this, &UCallbackProxy_GetGame::OnGetGameDelegate));
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioGame Game;
    OnFailure.Broadcast(Response, Game);
  }
}

void UCallbackProxy_GetGame::OnGetGameDelegate(FModioResponse Response, FModioGame Game)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Game);
  }
  else
  {
    OnFailure.Broadcast(Response, Game);
  }
}