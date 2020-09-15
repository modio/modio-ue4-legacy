// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetGame.h"

FModioAsyncRequest_GetGame::FModioAsyncRequest_GetGame(FModioSubsystem* Modio, FModioGameDelegate Delegate) :
  FModioAsyncRequest(Modio),
  ResponseDelegate(Delegate)
{
}

void FModioAsyncRequest_GetGame::Response(void* Object, ModioResponse ModioResponse, ModioGame InModioGame)
{
  FModioResponse Response;
  InitializeResponse(Response, ModioResponse);

  FModioGame Game;
  InitializeGame(Game, InModioGame);

  FModioAsyncRequest_GetGame* ThisPointer = (FModioAsyncRequest_GetGame*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound(Response, Game);

  ThisPointer->Done();
}