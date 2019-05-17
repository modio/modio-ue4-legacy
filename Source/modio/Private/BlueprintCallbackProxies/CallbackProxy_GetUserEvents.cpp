// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "CallbackProxy_GetUserEvents.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

UCallbackProxy_GetUserEvents::UCallbackProxy_GetUserEvents(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetUserEvents *UCallbackProxy_GetUserEvents::GetUserEvents(UObject *WorldContext, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetUserEvents *Proxy = NewObject<UCallbackProxy_GetUserEvents>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterType = FilterType;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetUserEvents::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->GetUserEvents( this->FilterType, this->Limit, this->Offset, FModioUserEventArrayDelegate::CreateUObject( this, &UCallbackProxy_GetUserEvents::OnGetUserEventsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioUserEvent> UserEvents;
    OnFailure.Broadcast( Response, UserEvents );
  }
}

void UCallbackProxy_GetUserEvents::OnGetUserEventsDelegate(FModioResponse Response, const TArray<FModioUserEvent> &UserEvents)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, UserEvents);
  }
  else
  {
    OnFailure.Broadcast(Response, UserEvents);
  }
}