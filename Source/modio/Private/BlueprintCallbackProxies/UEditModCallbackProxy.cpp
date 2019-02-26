// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UEditModCallbackProxy.h"

void onModEdited(void *object, ModioResponse modio_response, ModioMod modio_mod)
{
  UEditModCallbackProxy *edit_mod_proxy = (UEditModCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  FModioMod mod;
  InitializeMod(mod, modio_mod);
  edit_mod_proxy->OnEditModDelegate(response, mod);
}

UEditModCallbackProxy::UEditModCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UEditModCallbackProxy *UEditModCallbackProxy::EditMod(int32 ModId, FModioModEditor ModEditor)
{
  UEditModCallbackProxy *Proxy = NewObject<UEditModCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->ModEditor = ModEditor;
  return Proxy;
}

void UEditModCallbackProxy::Activate()
{
  ModioModEditor mod_editor;
  modioInitModEditor(&mod_editor);
  setupModioModEditor(this->ModEditor, mod_editor);
  modioEditMod(this, (u32)this->ModId, mod_editor, &onModEdited);
  modioFreeModEditor(&mod_editor);
}

void UEditModCallbackProxy::OnEditModDelegate(FModioResponse Response, FModioMod Mod)
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