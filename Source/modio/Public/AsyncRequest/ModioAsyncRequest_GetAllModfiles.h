// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModfile.h"

/**
* Callback returning all the mod files information requested
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_GetAllModfiles : public FModioAsyncRequest
{
public:
  static void Response(void* Object, ModioResponse Response, ModioModfile* Modfiles, u32 ModfilesSize);

protected:
  FModioAsyncRequest_GetAllModfiles(FModioSubsystem* Modio, FModioModfileArrayDelegate Delegate);

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest(FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters); 
private:
  FModioModfileArrayDelegate ResponseDelegate;
};