// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAllModTags.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAllModTags::UCallbackProxy_GetAllModTags(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAllModTags *UCallbackProxy_GetAllModTags::GetAllModTags( UObject *WorldContext, int32 ModId )
{
  UCallbackProxy_GetAllModTags *Proxy = NewObject<UCallbackProxy_GetAllModTags>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAllModTags::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetAllModTags( ModId, FModioModTagArrayDelegate::CreateUObject( this, &UCallbackProxy_GetAllModTags::OnGetAllModTagsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioModTag> Tags;
    OnFailure.Broadcast( Response, Tags );
  }
}

void UCallbackProxy_GetAllModTags::OnGetAllModTagsDelegate(FModioResponse Response, const TArray<FModioModTag> &Tags)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Tags);
  }
  else
  {
    OnFailure.Broadcast(Response, Tags);
  }
}