// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "GetAuthenticatedUserCallbackProxy.h"
#include "ModioSubsystem.h"

UGetAuthenticatedUserCallbackProxy::UGetAuthenticatedUserCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGetAuthenticatedUserCallbackProxy *UGetAuthenticatedUserCallbackProxy::GetAuthenticatedUser( UObject *WorldContextObject )
{
  UGetAuthenticatedUserCallbackProxy *Proxy = NewObject<UGetAuthenticatedUserCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContextObject;
  return Proxy;
}

void UGetAuthenticatedUserCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->GetAuthenticatedUser( FGetAuthenticatedUserDelegate::CreateUObject( this, &UGetAuthenticatedUserCallbackProxy::OnGetAuthenticatedUserDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioUser User;
    OnFailure.Broadcast( Response, User );
  }
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