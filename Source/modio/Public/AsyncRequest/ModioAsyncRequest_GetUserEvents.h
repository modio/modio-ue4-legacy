// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioUserEvent.h"

/**
* Callback returning all the events related to the authenticated user
* @param ModioResponse - Response from Modio backend
* @param Events - Event information retreived from mod.io
*/

class FModioAsyncRequest_GetUserEvents : public FModioAsyncRequest
{
public:
  static void Response(void *Object, ModioResponse ModioResponse, ModioUserEvent *ModioUserEvents, u32 ModioUserEventsSize);

protected:
  FModioAsyncRequest_GetUserEvents( FModioSubsystem* Modio, FModioUserEventArrayDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioUserEventArrayDelegate ResponseDelegate;
};