// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "GetUserSubscriptionsCallbackProxy.h"

void onGetUserSubscriptions(void *object, ModioResponse modio_response, ModioMod *modio_mods, u32 modio_mods_size)
{
  UGetUserSubscriptionsCallbackProxy *get_user_subscriptions_request_proxy = (UGetUserSubscriptionsCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  get_user_subscriptions_request_proxy->OnGetUserSubscriptionsDelegate(response, ConvertToTArrayMods(modio_mods, modio_mods_size));
}

UGetUserSubscriptionsCallbackProxy::UGetUserSubscriptionsCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGetUserSubscriptionsCallbackProxy *UGetUserSubscriptionsCallbackProxy::GetUserSubscriptions(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset)
{
  UGetUserSubscriptionsCallbackProxy *Proxy = NewObject<UGetUserSubscriptionsCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterType = FilterType;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  return Proxy;
}

void UGetUserSubscriptionsCallbackProxy::Activate()
{
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  SetupModioFilterCreator(this->FilterType, this->Limit, this->Offset, modio_filter_creator);
  modioGetUserSubscriptions(this, modio_filter_creator, &onGetUserSubscriptions);
  modioFreeFilter(&modio_filter_creator);
}

void UGetUserSubscriptionsCallbackProxy::OnGetUserSubscriptionsDelegate(FModioResponse Response, TArray<FModioMod> Mods)
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