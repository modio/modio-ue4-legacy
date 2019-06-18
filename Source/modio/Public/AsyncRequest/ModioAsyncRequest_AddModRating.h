#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a user rated a mod
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_AddModRating : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddModRating( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};