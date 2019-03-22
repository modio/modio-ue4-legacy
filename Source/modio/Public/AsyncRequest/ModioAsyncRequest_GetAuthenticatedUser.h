#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioUser.h"
#include "ModioAsyncRequest_GetAuthenticatedUser.generated.h"

/**
* Callback returning the information of the currently logged in user
* @param ModioResponse - Response from Modio backend
* @param User - User currently logged in
*/
DECLARE_DELEGATE_TwoParams( FGetAuthenticatedUserDelegate, FModioResponse, FModioUser );

class FModioAsyncRequest_GetAuthenticatedUser : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAuthenticatedUser( FModioSubsystem *Modio, FGetAuthenticatedUserDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioUser ModioUser);

private:
  FGetAuthenticatedUserDelegate ResponseDelegate;
};

// @todo: find a better workarround to create the generate.h in order to setup the delegate 
UCLASS()
class MODIO_API UGetAuthenticatedUserDelegateGenerator : public UObject
{
  GENERATED_BODY()
};