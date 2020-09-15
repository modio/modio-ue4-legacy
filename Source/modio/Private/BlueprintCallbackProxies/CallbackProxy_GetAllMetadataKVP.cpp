// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetAllMetadataKVP.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetAllMetadataKVP::UCallbackProxy_GetAllMetadataKVP(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetAllMetadataKVP *UCallbackProxy_GetAllMetadataKVP::GetAllMetadataKVP( UObject *WorldContext, int32 ModId )
{
  UCallbackProxy_GetAllMetadataKVP *Proxy = NewObject<UCallbackProxy_GetAllMetadataKVP>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetAllMetadataKVP::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetAllMetadataKVP( ModId, FModioMetadataKVPArrayDelegate::CreateUObject( this, &UCallbackProxy_GetAllMetadataKVP::OnGetAllMetadataKVPDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioMetadataKVP> MetadataKVP;
    OnFailure.Broadcast( Response, MetadataKVP );
  }
}

void UCallbackProxy_GetAllMetadataKVP::OnGetAllMetadataKVPDelegate(FModioResponse Response, const TArray<FModioMetadataKVP> &MetadataKVP)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, MetadataKVP);
  }
  else
  {
    OnFailure.Broadcast(Response, MetadataKVP);
  }
}