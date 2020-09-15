// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAuthenticatedUser.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAuthenticatedUser::UCallbackProxy_GetAuthenticatedUser(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAuthenticatedUser *UCallbackProxy_GetAuthenticatedUser::GetAuthenticatedUser( UObject *WorldContext )
{
  UCallbackProxy_GetAuthenticatedUser *Proxy = NewObject<UCallbackProxy_GetAuthenticatedUser>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAuthenticatedUser::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetAuthenticatedUser( FModioUserDelegate::CreateUObject( this, &UCallbackProxy_GetAuthenticatedUser::OnGetAuthenticatedUserDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    FModioUser User;
    OnFailure.Broadcast( Response, User );
  }
}

void UCallbackProxy_GetAuthenticatedUser::OnGetAuthenticatedUserDelegate(FModioResponse Response, FModioUser User)
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