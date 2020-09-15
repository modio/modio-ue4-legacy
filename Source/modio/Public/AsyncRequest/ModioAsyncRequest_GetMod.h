// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback returning all the mod profile information requested
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/

class FModioAsyncRequest_GetMod : public FModioAsyncRequest
{
public:
	FModioAsyncRequest_GetMod( FModioSubsystem *Modio, FModioModDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMod Mod );

private:
  FModioModDelegate ResponseDelegate;
};