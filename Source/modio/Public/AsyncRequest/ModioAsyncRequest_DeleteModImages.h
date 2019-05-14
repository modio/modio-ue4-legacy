#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when images were deleted from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteModImages : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteModImages( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};