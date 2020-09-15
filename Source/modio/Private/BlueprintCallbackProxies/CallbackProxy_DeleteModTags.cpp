// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DeleteModTags.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DeleteModTags::UCallbackProxy_DeleteModTags(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DeleteModTags *UCallbackProxy_DeleteModTags::DeleteModTags( UObject *WorldContext, int32 ModId, const TArray<FString> &Tags )
{
  UCallbackProxy_DeleteModTags *Proxy = NewObject<UCallbackProxy_DeleteModTags>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->Tags = Tags;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_DeleteModTags::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DeleteModTags( ModId, Tags, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_DeleteModTags::OnDeleteModTagsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_DeleteModTags::OnDeleteModTagsDelegate(FModioResponse Response)
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