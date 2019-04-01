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
  FModioAsyncRequest_SubscribeToMod( FModioSubsystem *Modio, FModioModDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod );

private:
  FModioModDelegate ResponseDelegate;
};