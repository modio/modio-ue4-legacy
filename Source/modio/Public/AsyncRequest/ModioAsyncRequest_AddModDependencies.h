// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"

/**
* Callback for when new dependencies were added to a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_AddModDependencies : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddModDependencies( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};