// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a user submits a report to mod.io
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_SubmitReport : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_SubmitReport( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};