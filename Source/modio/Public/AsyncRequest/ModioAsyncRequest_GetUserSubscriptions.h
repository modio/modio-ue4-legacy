#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback returning all the mod profiles the user is subcribed
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/

class FModioAsyncRequest_GetUserSubscriptions : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetUserSubscriptions( FModioSubsystem *Modio, FModioModArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize);

private:
  FModioModArrayDelegate ResponseDelegate;
};