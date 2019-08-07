// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAllModsFiltered.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAllModsFiltered::UCallbackProxy_GetAllModsFiltered(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAllModsFiltered *UCallbackProxy_GetAllModsFiltered::GetAllModsFiltered(UObject *WorldContext, FModioFilterCreator Filter, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetAllModsFiltered *Proxy = NewObject<UCallbackProxy_GetAllModsFiltered>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Filter = Filter;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAllModsFiltered::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetAllModsFiltered( this->Filter, this->Limit, this->Offset, FModioModArrayDelegate::CreateUObject( this, &UCallbackProxy_GetAllModsFiltered::OnGetAllModsFilteredDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMod> Mods;
    OnFailure.Broadcast( Response, Mods );
  }
}

void UCallbackProxy_GetAllModsFiltered::OnGetAllModsFilteredDelegate(FModioResponse Response, const TArray<FModioMod> &Mods)
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