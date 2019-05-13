#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when sketchfab links were deleted from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteModSketchfabLinks : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteModSketchfabLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};