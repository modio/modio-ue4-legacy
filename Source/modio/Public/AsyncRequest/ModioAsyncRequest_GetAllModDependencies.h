#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"

/**
* Callback returning all the dependencies corresponding to a mod
* @param ModioResponse - Response from Modio backend
* @param Dependencies - Dependencies assigned to the corresponding mod
*/

class FModioAsyncRequest_GetAllModDependencies : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAllModDependencies( FModioSubsystem *Modio, FModioModDependencyArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioDependency *ModioDependencies, u32 ModioDependenciesSize);
private:
  FModioModDependencyArrayDelegate ResponseDelegate;
};