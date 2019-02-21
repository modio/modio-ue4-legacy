// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UAddModCallbackProxy.h"

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

  modioSetModCreatorMaturityOption(&mod_creator, (u32)this->ModCreator.MaturityOption);
  modioSetModCreatorVisible(&mod_creator, this->ModCreator.Visible);
  if (this->ModCreator.LogoPath != "")
    modioSetModCreatorLogoPath(&mod_creator, TCHAR_TO_UTF8(*this->ModCreator.LogoPath));
  if (this->ModCreator.Name != "")
    modioSetModCreatorName(&mod_creator, TCHAR_TO_UTF8(*this->ModCreator.Name));
  if (this->ModCreator.NameId != "")
    modioSetModCreatorNameid(&mod_creator, TCHAR_TO_UTF8(*this->ModCreator.NameId));
  if (this->ModCreator.Summary != "")
    modioSetModCreatorSummary(&mod_creator, TCHAR_TO_UTF8(*this->ModCreator.Summary));
  if (this->ModCreator.Description != "")
    modioSetModCreatorDescription(&mod_creator, TCHAR_TO_UTF8(*this->ModCreator.Description));
  if (this->ModCreator.HomepageUrl != "")
    modioSetModCreatorHomepageURL(&mod_creator, TCHAR_TO_UTF8(*this->ModCreator.HomepageUrl));

  modioAddMod(this, mod_creator, &onModAdded);
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