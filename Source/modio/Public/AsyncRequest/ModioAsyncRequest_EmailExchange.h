#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"

/**
* Callback for when a security code has been exchanged
* @param ModioResponse - Response from Modio backend
*/

class FModioAsyncRequest_EmailExchange : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_EmailExchange( FModioSubsystem *Modio, FModioGenericDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FModioGenericDelegate ResponseDelegate;
};