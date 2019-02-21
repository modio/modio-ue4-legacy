// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UGetAuthenticatedUserCallbackProxy.h"

void onModioGetAuthenticatedUser(void *object, ModioResponse modio_response, ModioUser modio_user)
{
  UGetAuthenticatedUserCallbackProxy *get_authenticated_user_proxy = (UGetAuthenticatedUserCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  FModioUser user;
  InitializeUser(user, modio_user);
  get_authenticated_user_proxy->OnGetAuthenticatedUserDelegate(response, user);
}

UGetAuthenticatedUserCallbackProxy::UGetAuthenticatedUserCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGetAuthenticatedUserCallbackProxy *UGetAuthenticatedUserCallbackProxy::GetAuthenticatedUser()
{
  UGetAuthenticatedUserCallbackProxy *Proxy = NewObject<UGetAuthenticatedUserCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  return Proxy;
}

void UGetAuthenticatedUserCallbackProxy::Activate()
{
  modioGetAuthenticatedUser(this, &onModioGetAuthenticatedUser);
}

void UGetAuthenticatedUserCallbackProxy::OnGetAuthenticatedUserDelegate(FModioResponse Response, FModioUser User)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, User);
  }
  else
  {
    OnFailure.Broadcast(Response, User);
  }
}