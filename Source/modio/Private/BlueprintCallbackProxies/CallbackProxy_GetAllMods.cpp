// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAllMods.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAllMods::UCallbackProxy_GetAllMods(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAllMods *UCallbackProxy_GetAllMods::GetAllMods(UObject *WorldContext, TEnumAsByte<EModioModSortType> ModSortType, TArray<FString> ModTags, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetAllMods *Proxy = NewObject<UCallbackProxy_GetAllMods>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModSortType = ModSortType;
  Proxy->ModTags = ModTags;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAllMods::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetAllMods( this->ModSortType, this->ModTags, this->Limit, this->Offset, FModioModArrayDelegate::CreateUObject( this, &UCallbackProxy_GetAllMods::OnGetAllModsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMod> Mods;
    OnFailure.Broadcast( Response, Mods );
  }
}

void UCallbackProxy_GetAllMods::OnGetAllModsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods)
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