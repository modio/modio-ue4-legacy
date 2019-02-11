// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UEmailRequestCallbackProxy.h"

void onModioEmailRequest(void *object, ModioResponse response)
{
  UEmailRequestCallbackProxy *email_request_proxy = (UEmailRequestCallbackProxy *)object;
  email_request_proxy->OnEmailRequestDelegate((int32)response.code);
}

UEmailRequestCallbackProxy::UEmailRequestCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UEmailRequestCallbackProxy *UEmailRequestCallbackProxy::EmailRequest(FString email)
{
  UEmailRequestCallbackProxy *Proxy = NewObject<UEmailRequestCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->email = email;
  return Proxy;
}

void UEmailRequestCallbackProxy::Activate()
{
  modioEmailRequest(this, TCHAR_TO_UTF8(*this->email), &onModioEmailRequest);
}

void UEmailRequestCallbackProxy::OnEmailRequestDelegate(int32 Result)
{
  if (Result >= 200 && Result < 300)
  {
    OnSuccess.Broadcast(Result);
  }
  else
  {
    OnFailure.Broadcast(Result);
  }
}