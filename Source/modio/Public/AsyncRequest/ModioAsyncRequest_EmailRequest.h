#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "ModioAsyncRequest_EmailRequest.generated.h"

/**
* Callback for when a email request has been done
* @param ModioResponse - Response from Modio backend
*/
DECLARE_DELEGATE_OneParam( FEmailRequestDelegate, FModioResponse );

class FModioAsyncRequest_EmailRequest : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_EmailRequest( FModioSubsystem *Modio, FEmailRequestDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse );

private:
  FEmailRequestDelegate ResponseDelegate;
};

// @todo: find a better workarround to create the generate.h in order to setup the delegate 
UCLASS()
class MODIO_API UEmailRequestDelegateGenerator : public UObject
{
  GENERATED_BODY()
};