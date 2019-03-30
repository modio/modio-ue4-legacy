#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"

/**
* Callback returning all the mod profile information requested
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/

class FModioAsyncRequest_DeleteModDependencies : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteModDependencies( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};