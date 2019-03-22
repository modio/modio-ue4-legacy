#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "ModioAsyncRequest_EditMod.generated.h"

/**
* Callback for when a mod profile has been edited
* @param ModioResponse - Response from Modio backend
* @param Mod - The mod that was just edited
*/
DECLARE_DELEGATE_TwoParams( FEditModDelegate, FModioResponse, FModioMod );

class FModioAsyncRequest_EditMod : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_EditMod( FModioSubsystem *Modio, FEditModDelegate Delegate );

  static void Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod );

private:
  FEditModDelegate ResponseDelegate;
};

// @todo: find a better workarround to create the generate.h in order to setup the delegate 
UCLASS()
class MODIO_API UEditModDelegateGenerator : public UObject
{
  GENERATED_BODY()
};