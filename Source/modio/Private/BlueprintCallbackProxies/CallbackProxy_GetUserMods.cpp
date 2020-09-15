// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetUserMods.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetUserMods::UCallbackProxy_GetUserMods(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetUserMods *UCallbackProxy_GetUserMods::GetUserMods(UObject *WorldContext, FModioFilterCreator FilterCreator, TArray<FString> ModTags, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetUserMods *Proxy = NewObject<UCallbackProxy_GetUserMods>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterCreator = FilterCreator;
  Proxy->ModTags = ModTags;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetUserMods::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetUserMods( this->FilterCreator, this->ModTags, this->Limit, this->Offset, FModioModArrayDelegate::CreateUObject( this, &UCallbackProxy_GetUserMods::OnGetUserModsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMod> Mods;
    OnFailure.Broadcast( Response, Mods );
  }
}

void UCallbackProxy_GetUserMods::OnGetUserModsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods)
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