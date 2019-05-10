#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModTag.h"

/**
* Callback for when new tags were added to a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_AddModTags : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddModTags( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};