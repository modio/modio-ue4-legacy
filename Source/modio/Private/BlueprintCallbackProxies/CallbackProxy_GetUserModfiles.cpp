// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "CallbackProxy_GetUserModfiles.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"

UCallbackProxy_GetUserModfiles::UCallbackProxy_GetUserModfiles(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetUserModfiles *UCallbackProxy_GetUserModfiles::GetUserModfiles(UObject *WorldContext, TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetUserModfiles *Proxy = NewObject<UCallbackProxy_GetUserModfiles>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->FilterType = FilterType;
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetUserModfiles::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  if( FModioSubsystemPtr Modio = FModioSubsystem::Get( World ) )
  {
    Modio->GetUserModfiles( this->FilterType, this->Limit, this->Offset, FModioModfileArrayDelegate::CreateUObject( this, &UCallbackProxy_GetUserModfiles::OnGetUserModfilesDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioModfile> Modfiles;
    OnFailure.Broadcast( Response, Modfiles );
  }
}

void UCallbackProxy_GetUserModfiles::OnGetUserModfilesDelegate(FModioResponse Response, const TArray<FModioModfile> &Modfiles)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Modfiles);
  }
  else
  {
    OnFailure.Broadcast(Response, Modfiles);
  }
}