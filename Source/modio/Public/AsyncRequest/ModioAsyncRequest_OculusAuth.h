// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a user logins with his Oculus account
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_OculusAuth : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_OculusAuth( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};