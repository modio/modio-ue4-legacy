// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioUser.h"

/**
* Callback returning the information of the currently logged in user
* @param ModioResponse - Response from Modio backend
* @param User - User currently logged in
*/

class FModioAsyncRequest_GetAuthenticatedUser : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAuthenticatedUser( FModioSubsystem *Modio, FModioUserDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioUser ModioUser);

private:
  FModioUserDelegate ResponseDelegate;
};