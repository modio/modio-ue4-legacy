// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModfile.h"

/**
* Callback returning all the mods the authenticated user owns
* @param ModioResponse - Response from Modio backend
* @param Modfiles - Modfiles information retreived from mod.io
*/

class FModioAsyncRequest_GetUserModfiles : public FModioAsyncRequest
{
public:
  static void Response(void *Object, ModioResponse ModioResponse, ModioModfile *ModioModfiles, u32 ModioModfilesSize);

protected:
  FModioAsyncRequest_GetUserModfiles( FModioSubsystem* Modio, FModioModfileArrayDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioModfileArrayDelegate ResponseDelegate;
};