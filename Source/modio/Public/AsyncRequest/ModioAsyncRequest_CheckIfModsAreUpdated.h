// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a update check was made
* @param ModioResponse - Response from Modio backend
* @param bool - True if all mods are updated, otherwise returns false
*/

class FModioAsyncRequest_CheckIfModsAreUpdated : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_CheckIfModsAreUpdated( FModioSubsystem *Modio, FModioBooleanDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, bool ModsAreUpdated );

private:
  FModioBooleanDelegate ResponseDelegate;
};