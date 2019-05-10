#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a user logins with his GOG account
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_GalaxyAuth : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GalaxyAuth( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};