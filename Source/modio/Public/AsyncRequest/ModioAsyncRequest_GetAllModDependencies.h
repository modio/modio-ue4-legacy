#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"

/**
* Callback returning all the mod profile information requested
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/

class FModioAsyncRequest_GetAllModDependencies : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAllModDependencies( FModioSubsystem *Modio, FModioModDependencyArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioDependency *ModioDependencies, u32 ModioDependenciesSize);
private:
  FModioModDependencyArrayDelegate ResponseDelegate;
};