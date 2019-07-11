// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback returning all the mods the authenticated user owns
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/

class FModioAsyncRequest_GetUserMods : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetUserMods( FModioSubsystem *Modio, FModioModArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize);

private:
  FModioModArrayDelegate ResponseDelegate;
};