// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UEmailRequestCallbackProxy.h"

void onModioEmailRequest(void *object, ModioResponse modio_response)
{
  UEmailRequestCallbackProxy *email_request_proxy = (UEmailRequestCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  email_request_proxy->OnEmailRequestDelegate(response);
}

UEmailRequestCallbackProxy::UEmailRequestCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
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
  modioEmailRequest(this, TCHAR_TO_UTF8(*this->Email), &onModioEmailRequest);
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