#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a user logins with his GOG account
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_SteamAuth : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_SteamAuth( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};