// Copyright 2019 modio. All Rights Reserved.
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
  FModioAsyncRequest_GetAllMetadataKVP( FModioSubsystem *Modio, FModioMetadataKVPArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMetadataKVP *ModioMetadataKVP, u32 ModioMetadataKVPize);
private:
  FModioMetadataKVPArrayDelegate ResponseDelegate;
};