// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Updates subscribed and installed mods
* @param ModioResponse - Response from Modio backend
* @param bool - True if all mods are updated, otherwise returns false
*/

class FModioAsyncRequest_DownloadSubscribedModfiles : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DownloadSubscribedModfiles( FModioSubsystem *Modio, FModioBooleanDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, bool ModsAreUpdated );

private:
  FModioBooleanDelegate ResponseDelegate;
};