// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetUserSubscriptions.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetUserSubscriptions::UCallbackProxy_GetUserSubscriptions(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetUserSubscriptions *UCallbackProxy_GetUserSubscriptions::GetUserSubscriptions(UObject *WorldContext, FModioFilterCreator FilterCreator, TArray<FString> ModTags, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetUserSubscriptions *Proxy = NewObject<UCallbackProxy_GetUserSubscriptions>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterCreator = FilterCreator;
  Proxy->ModTags = ModTags;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetUserSubscriptions::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetUserSubscriptions( this->FilterCreator, this->ModTags, this->Limit, this->Offset, FModioModArrayDelegate::CreateUObject( this, &UCallbackProxy_GetUserSubscriptions::OnGetUserSubscriptionsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMod> Mods;
    OnFailure.Broadcast( Response, Mods );
  }
}

void UCallbackProxy_GetUserSubscriptions::OnGetUserSubscriptionsDelegate(FModioResponse Response, const TArray<FModioMod> &Mods)
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