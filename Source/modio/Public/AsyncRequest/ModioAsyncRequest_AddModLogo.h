#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a logo image has been added
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_AddModLogo : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddModLogo( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};