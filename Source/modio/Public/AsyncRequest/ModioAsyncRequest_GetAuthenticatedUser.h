// Copyright 2020 modio. All Rights Reserved.
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
  static void Response(void *Object, ModioResponse ModioResponse, ModioUser ModioUser);

protected:
  FModioAsyncRequest_GetAuthenticatedUser( FModioSubsystem* Modio, FModioUserDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioUserDelegate ResponseDelegate;
};