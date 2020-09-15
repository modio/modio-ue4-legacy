// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddModTags.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddModTags::UCallbackProxy_AddModTags(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddModTags *UCallbackProxy_AddModTags::AddModTags( UObject *WorldContext, int32 ModId, const TArray<FString> &Tags )
{
  UCallbackProxy_AddModTags *Proxy = NewObject<UCallbackProxy_AddModTags>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->Tags = Tags;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_AddModTags::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModTags( ModId, Tags, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddModTags::OnAddModTagsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddModTags::OnAddModTagsDelegate(FModioResponse Response)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response);
  }
  else
  {
    OnFailure.Broadcast(Response);
  }
}