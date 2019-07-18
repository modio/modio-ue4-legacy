// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback for when a new mod profile has been created
* @param ModioResponse - Response from Modio backend
* @param Mod - The mod that was just created
*/

class FModioAsyncRequest_AddMod : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddMod( FModioSubsystem *Modio, FModioModDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod );

private:
  FModioModDelegate ResponseDelegate;
};