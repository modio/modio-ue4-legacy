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
  FModioAsyncRequest_GetUserEvents( FModioSubsystem *Modio, FModioUserEventArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioUserEvent *ModioUserEvents, u32 ModioUserEventsSize);

private:
  FModioUserEventArrayDelegate ResponseDelegate;
};