#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioModTag.h"

/**
* Callback returning all the tags corresponding to a mod
* @param ModioResponse - Response from Modio backend
* @param Tags - Tags assigned to the corresponding mod
*/

class FModioAsyncRequest_GetAllModTags : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAllModTags( FModioSubsystem *Modio, FModioModTagsArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioTag *ModioTags, u32 ModioTagsSize);
private:
  FModioModTagsArrayDelegate ResponseDelegate;
};