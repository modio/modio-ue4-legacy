// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when an authentication email request has been sent
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_EmailRequest : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_EmailRequest( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};