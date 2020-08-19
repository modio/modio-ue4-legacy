// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioGame.h"

/**
* Callback returning the game information requested
* @param ModioResponse - Response from Modio backend
* @param game - Game information retrieved from mod.io
*/

class FModioAsyncRequest_GetGame : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetGame(FModioSubsystem* Modio, FModioGameDelegate Delegate);

  static void Response(void* Object, ModioResponse ModioResponse, ModioGame Game);

private:
  FModioGameDelegate ResponseDelegate;
};