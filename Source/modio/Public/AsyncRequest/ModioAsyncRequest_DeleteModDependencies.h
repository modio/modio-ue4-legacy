// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

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
  static void Response(void *Object, ModioResponse ModioResponse );

protected:
  FModioAsyncRequest_DeleteModDependencies( FModioSubsystem* Modio, FModioGenericDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioGenericDelegate ResponseDelegate;
};