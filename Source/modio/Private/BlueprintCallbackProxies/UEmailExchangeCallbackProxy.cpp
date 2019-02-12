// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UEmailExchangeCallbackProxy.h"

void onModioEmailExchange(void *object, ModioResponse modio_response)
{
  UEmailExchangeCallbackProxy *email_exchange_proxy = (UEmailExchangeCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  email_exchange_proxy->OnEmailExchangeDelegate(response);
}

UEmailExchangeCallbackProxy::UEmailExchangeCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UEmailExchangeCallbackProxy *UEmailExchangeCallbackProxy::EmailExchange(FString SecurityCode)
{
  UEmailExchangeCallbackProxy *Proxy = NewObject<UEmailExchangeCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->SecurityCode = SecurityCode;
  return Proxy;
}

void UEmailExchangeCallbackProxy::Activate()
{
  modioEmailExchange(this, TCHAR_TO_UTF8(*this->SecurityCode), &onModioEmailExchange);
}

void UEmailExchangeCallbackProxy::OnEmailExchangeDelegate(FModioResponse Response)
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