#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModfile.h"

/**
* Callback returning all the mods the authenticated user owns
* @param ModioResponse - Response from Modio backend
* @param Modfiles - Modfiles information retreived from mod.io
*/

class FModioAsyncRequest_GetUserModfiles : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetUserModfiles( FModioSubsystem *Modio, FModioModfileArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioModfile *ModioModfiles, u32 ModioModfilesSize);

private:
  FModioModfileArrayDelegate ResponseDelegate;
};