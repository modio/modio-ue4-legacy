// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "GetAllModsCallbackProxy.h"
#include "ModioSubsystem.h"

UGetAllModsCallbackProxy::UGetAllModsCallbackProxy(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UGetAllModsCallbackProxy *UGetAllModsCallbackProxy::GetAllMods(UObject *WorldContextObject, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset)
{
  UGetAllModsCallbackProxy *Proxy = NewObject<UGetAllModsCallbackProxy>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterType = FilterType;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContextObject;
  return Proxy;
}

void UGetAllModsCallbackProxy::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->GetAllMods( this->FilterType, this->Limit, this->Offset, FModioModArrayDelegate::CreateUObject( this, &UGetAllModsCallbackProxy::OnGetAllModsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMod> Mods;
    OnFailure.Broadcast( Response, Mods );
  }
}

void UGetAllModsCallbackProxy::OnGetAllModsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods)
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