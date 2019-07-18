// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModDependency.h"

/**
* Callback for when tags were removed from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteModTags : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteModTags( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};