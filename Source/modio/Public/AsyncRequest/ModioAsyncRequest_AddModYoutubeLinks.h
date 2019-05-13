#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when new youtube links were added to a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_AddModYoutubeLinks : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddModYoutubeLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};