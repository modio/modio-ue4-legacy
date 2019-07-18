// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"

/**
* Callback for when mod profile has been edited
* @param ModioResponse - Response from Modio backend
* @param Mod - The mod that was just edited
*/

class FModioAsyncRequest_EditMod : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_EditMod( FModioSubsystem *Modio, FModioModDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod );

private:
  FModioModDelegate ResponseDelegate;
};