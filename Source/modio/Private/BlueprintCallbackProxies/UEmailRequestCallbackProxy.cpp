// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UEmailRequestCallbackProxy.h"

UEmailRequestCallbackProxy::UEmailRequestCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
  EmailRequestDelegate.BindUObject( this, &UEmailRequestCallbackProxy::OnEmailRequestDelegate);
}

UEmailRequestCallbackProxy *UEmailRequestCallbackProxy::EmailRequest(FString Email)
{
  UEmailRequestCallbackProxy *Proxy = NewObject<UEmailRequestCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Email = Email;
  return Proxy;
}

void UEmailRequestCallbackProxy::Activate()
{
  UModioFunctionLibrary::EmailRequest(TCHAR_TO_UTF8(*this->Email), EmailRequestDelegate);
}

void UEmailRequestCallbackProxy::OnEmailRequestDelegate(FModioResponse Response)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response);
  }
  else
  {
    OnFailure.Broadcast(Response);
  }
}