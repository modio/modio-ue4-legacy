// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMetadataKVP.h"

/**
* Callback returning all the metadata kvp corresponding to a mod
* @param ModioResponse - Response from Modio backend
* @param MetadataKVP - Metadata kvp assigned to the corresponding mod
*/

class FModioAsyncRequest_GetAllMetadataKVP : public FModioAsyncRequest
{
public:
  static void Response(void *Object, ModioResponse ModioResponse, ModioMetadataKVP *ModioMetadataKVP, u32 ModioMetadataKVPize);

protected:
  FModioAsyncRequest_GetAllMetadataKVP( FModioSubsystem* Modio, FModioMetadataKVPArrayDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType, typename... Params>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate, Params... Parameters );
private:
  FModioMetadataKVPArrayDelegate ResponseDelegate;
};