#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioMod.h"
#include "ModioAsyncRequest_GetAllMods.generated.h"

/**
* Callback returning all the mod profile information requested
* @param ModioResponse - Response from Modio backend
* @param Mods - Mods information retreived from mod.io
*/
DECLARE_DELEGATE_TwoParams( FGetAllModsDelegate, FModioResponse, const TArray<FModioMod> & );

class FModioAsyncRequest_GetAllMods : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_GetAllMods( FModioSubsystem *Modio, FGetAllModsDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize);

private:
  FGetAllModsDelegate ResponseDelegate;
};

// @todo: find a better workarround to create the generate.h in order to setup the delegate 
UCLASS()
class MODIO_API UGetAllModsDelegateGenerator : public UObject
{
  GENERATED_BODY()
};