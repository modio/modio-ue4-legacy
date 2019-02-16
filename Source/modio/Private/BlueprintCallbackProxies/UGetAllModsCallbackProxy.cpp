// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UGetAllModsCallbackProxy.h"

void onGetAllMods(void *object, ModioResponse modio_response, ModioMod *modio_mods, u32 modio_mods_size)
{
  UGetAllModsCallbackProxy *get_all_mods_request_proxy = (UGetAllModsCallbackProxy *)object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  get_all_mods_request_proxy->OnGetAllModsDelegate(response, toTArrayMods(modio_mods, modio_mods_size));
}

UGetAllModsCallbackProxy::UGetAllModsCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGetAllModsCallbackProxy *UGetAllModsCallbackProxy::GetAllMods(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset)
{
  UGetAllModsCallbackProxy *Proxy = NewObject<UGetAllModsCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterType = FilterType;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  return Proxy;
}

void UGetAllModsCallbackProxy::Activate()
{
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  modioSetFilterLimit(&modio_filter_creator, (u32)this->Limit);
  modioSetFilterOffset(&modio_filter_creator, (u32)this->Offset);

  switch (this->FilterType)
  {
  case EModioFilterType::SORT_BY_ID:
    break;
  case EModioFilterType::SORT_BY_RATING:
    modioSetFilterSort(&modio_filter_creator, (char *)"rating", false);
    break;
  case EModioFilterType::SORT_BY_DATE_LIVE:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_live", false);
    break;
  case EModioFilterType::SORT_BY_DATE_UPDATED:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_updated", false);
    break;
  default:
    // @todo: handle error
    break;
  }

  modioGetAllMods(this, modio_filter_creator, &onGetAllMods);
}

void UGetAllModsCallbackProxy::OnGetAllModsDelegate(FModioResponse Response, TArray<FModioMod> Mods)
{
  FString oa;
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Mods);
  }
  else
  {
    OnFailure.Broadcast(Response, Mods);
  }
}