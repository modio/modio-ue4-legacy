#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"

/**
* Callback for when dependencies were removed from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteModDependencies : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteModDependencies( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};