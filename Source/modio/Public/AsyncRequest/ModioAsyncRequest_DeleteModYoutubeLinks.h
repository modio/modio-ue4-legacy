#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when youtube links were deleted from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteModYoutubeLinks : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteModYoutubeLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};