#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMetadataKVP.h"

/**
* Callback returning all the metadata kvp corresponding to a mod
* @param ModioResponse - Response from Modio backend
* @param MetadataKVPs - Metadata kvp assigned to the corresponding mod
*/

class FModioAsyncRequest_GetAllMetadataKVPs : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAllMetadataKVPs( FModioSubsystem *Modio, FModioMetadataKVPArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMetadataKVP *ModioMetadataKVPs, u32 ModioMetadataKVPsSize);
private:
  FModioMetadataKVPArrayDelegate ResponseDelegate;
};