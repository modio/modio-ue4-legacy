// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_DeleteMetadataKVP.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_DeleteMetadataKVP::UCallbackProxy_DeleteMetadataKVP(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_DeleteMetadataKVP *UCallbackProxy_DeleteMetadataKVP::DeleteMetadataKVP( UObject *WorldContext, int32 ModId, const TMap<FString, FString> &MetadataKVP )
{
  UCallbackProxy_DeleteMetadataKVP *Proxy = NewObject<UCallbackProxy_DeleteMetadataKVP>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->ModId = ModId;
  Proxy->MetadataKVP = MetadataKVP;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_DeleteMetadataKVP::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->DeleteMetadataKVP( ModId, MetadataKVP, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_DeleteMetadataKVP::OnDeleteMetadataKVPDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_DeleteMetadataKVP::OnDeleteMetadataKVPDelegate(FModioResponse Response)
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