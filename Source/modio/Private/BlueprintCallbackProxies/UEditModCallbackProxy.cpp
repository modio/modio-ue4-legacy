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

  // @todo handle maturity option and visibility edition
  //modioSetModEditorMaturityOption(&mod_editor, (u32)this->ModCreator.MaturityOption);
  //modioSetModCreatorVisible(&mod_creator, this->ModCreator.Visible);
  if (this->ModEditor.Name != "")
    modioSetModEditorName(&mod_editor, TCHAR_TO_UTF8(*this->ModEditor.Name));
  if (this->ModEditor.NameId != "")
    modioSetModEditorNameid(&mod_editor, TCHAR_TO_UTF8(*this->ModEditor.NameId));
  if (this->ModEditor.Summary != "")
    modioSetModEditorSummary(&mod_editor, TCHAR_TO_UTF8(*this->ModEditor.Summary));
  if (this->ModEditor.Description != "")
    modioSetModEditorDescription(&mod_editor, TCHAR_TO_UTF8(*this->ModEditor.Description));
  if (this->ModEditor.HomepageUrl != "")
    modioSetModEditorHomepageURL(&mod_editor, TCHAR_TO_UTF8(*this->ModEditor.HomepageUrl));

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