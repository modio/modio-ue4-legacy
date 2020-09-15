// Copyright 2020 modio. All Rights Reserved.
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
  static void Response(void* Object, ModioResponse ModioResponse, ModioGame Game);
protected:
  FModioAsyncRequest_GetGame(FModioSubsystem* Modio, FModioGameDelegate Delegate);

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest(FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters);

  FModioGameDelegate ResponseDelegate;
};