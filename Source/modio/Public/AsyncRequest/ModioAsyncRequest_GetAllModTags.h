// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

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
  static void Response(void *Object, ModioResponse ModioResponse, ModioTag *ModioTags, u32 ModioTagsSize);

protected:
  FModioAsyncRequest_GetAllModTags( FModioSubsystem* Modio, FModioModTagArrayDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioModTagArrayDelegate ResponseDelegate;
};