// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback for when a user subscribed to a mod
* @param ModioResponse - Response from Modio backend
* @param Mod - The mod that the user has just subscribed to
*/

class FModioAsyncRequest_SubscribeToMod : public FModioAsyncRequest
{
public:
  static void Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod );

protected:
  FModioAsyncRequest_SubscribeToMod( FModioSubsystem* Modio, FModioModDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioModDelegate ResponseDelegate;
};