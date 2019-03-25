// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "GetUserSubscriptionsCallbackProxy.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

UGetUserSubscriptionsCallbackProxy::UGetUserSubscriptionsCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGetUserSubscriptionsCallbackProxy *UGetUserSubscriptionsCallbackProxy::GetUserSubscriptions(UObject *WorldContextObject, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset)
{
  UGetUserSubscriptionsCallbackProxy *Proxy = NewObject<UGetUserSubscriptionsCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterType = FilterType;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContextObject;
  return Proxy;
}

void UGetUserSubscriptionsCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->GetUserSubscriptions( this->FilterType, this->Limit, this->Offset, FModioModArrayDelegate::CreateUObject( this, &UGetUserSubscriptionsCallbackProxy::OnGetUserSubscriptionsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMod> Mods;
    OnFailure.Broadcast( Response, Mods );
  }
}

void UGetUserSubscriptionsCallbackProxy::OnGetUserSubscriptionsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Mods);
  }
  else
  {
    OnFailure.Broadcast(Response, Mods);
  }
}