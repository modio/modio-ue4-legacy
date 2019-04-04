#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback for when a user unsubscribed from a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_UnsubscribeFromMod : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_UnsubscribeFromMod( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};