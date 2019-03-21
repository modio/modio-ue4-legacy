// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AddModCallbackProxy.h"

void onModAdded(void *object, ModioResponse modio_response, ModioMod modio_mod)
{
  UAddModCallbackProxy *add_mod_proxy = (UAddModCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  FModioMod mod;
  InitializeMod(mod, modio_mod);
  add_mod_proxy->OnAddModDelegate(response, mod);
}

UAddModCallbackProxy::UAddModCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UAddModCallbackProxy *UAddModCallbackProxy::AddMod(FModioModCreator ModCreator)
{
  UAddModCallbackProxy *Proxy = NewObject<UAddModCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModCreator = ModCreator;
  return Proxy;
}

void UAddModCallbackProxy::Activate()
{
  ModioModCreator mod_creator;
  modioInitModCreator(&mod_creator);
  SetupModioModCreator(this->ModCreator, mod_creator);
  modioAddMod(this, mod_creator, &onModAdded);
  modioFreeModCreator(&mod_creator);
}

void UAddModCallbackProxy::OnAddModDelegate(FModioResponse Response, FModioMod Mod)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Mod);
  }
  else
  {
    OnFailure.Broadcast(Response, Mod);
  }
}