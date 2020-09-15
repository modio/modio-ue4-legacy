// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_AddMetadataKVP.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_AddMetadataKVP::UCallbackProxy_AddMetadataKVP(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_AddMetadataKVP *UCallbackProxy_AddMetadataKVP::AddMetadataKVP( UObject *WorldContext, int32 ModId, const TMap<FString, FString> &MetadataKVP )
{
  UCallbackProxy_AddMetadataKVP *Proxy = NewObject<UCallbackProxy_AddMetadataKVP>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->MetadataKVP = MetadataKVP;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_AddMetadataKVP::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddMetadataKVP( ModId, MetadataKVP, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_AddMetadataKVP::OnAddMetadataKVPDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_AddMetadataKVP::OnAddMetadataKVPDelegate(FModioResponse Response)
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