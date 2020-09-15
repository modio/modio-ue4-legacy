// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

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
  static void Response(void *Object, ModioResponse ModioResponse, ModioDependency *ModioDependencies, u32 ModioDependenciesSize);

protected:
  FModioAsyncRequest_GetAllModDependencies( FModioSubsystem* Modio, FModioModDependencyArrayDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioModDependencyArrayDelegate ResponseDelegate;
};