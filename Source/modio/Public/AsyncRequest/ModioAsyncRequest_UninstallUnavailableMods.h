// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback returned when all unavailable mods were uninstalled
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_UninstallUnavailableMods : public FModioAsyncRequest
{
public:
  int32 PendingCalls;
  TArray<int32> AvailableMods;

  FModioAsyncRequest_UninstallUnavailableMods( FModioSubsystem *Modio, FModioGenericDelegate Delegate, int32 PendingCalls );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize);

private:
  FModioGenericDelegate ResponseDelegate;
};