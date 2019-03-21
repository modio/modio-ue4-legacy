#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "ModioAsyncRequest_AddMod.generated.h"

/**
* Callback for when a new mod profile has been created
* @param ModioResponse - Response from Modio backend
* @param Mod - The mod that was just created
*/
DECLARE_DELEGATE_TwoParams( FAddModDelegate, FModioResponse, FModioMod );

class FModioAsyncRequest_AddMod : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_AddMod( FModioSubsystem *Modio, FAddModDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod );

private:
  FAddModDelegate ResponseDelegate;
};

// @todo: find a better workarround to create the generate.h in order to setup the delegate 
UCLASS()
class MODIO_API UAddModDelegateGenerator : public UObject
{
  GENERATED_BODY()
};