#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMetadataKVP.h"

/**
* Callback for when new tags were added to a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_DeleteMetadataKVP : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_DeleteMetadataKVP( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};