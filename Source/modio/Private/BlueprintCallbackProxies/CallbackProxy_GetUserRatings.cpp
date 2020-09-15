// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_GetUserRatings.h"
#include "ModioUE4Utility.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_GetUserRatings::UCallbackProxy_GetUserRatings(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_GetUserRatings *UCallbackProxy_GetUserRatings::GetUserRatings(UObject *WorldContext, int32 Limit, int32 Offset)
{
  UCallbackProxy_GetUserRatings *Proxy = NewObject<UCallbackProxy_GetUserRatings>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->Limit = Limit;
  Proxy->Offset = Offset;
  Proxy->WorldContextObject = WorldContext;
  return Proxy;
}

void UCallbackProxy_GetUserRatings::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->GetUserRatings( this->Limit, this->Offset, FModioRatingArrayDelegate::CreateUObject( this, &UCallbackProxy_GetUserRatings::OnGetUserRatingsDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    TArray<FModioRating> Ratings;
    OnFailure.Broadcast( Response, Ratings );
  }
}

void UCallbackProxy_GetUserRatings::OnGetUserRatingsDelegate(FModioResponse Response, const TArray<FModioRating> &Ratings)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response, Ratings);
  }
  else
  {
    OnFailure.Broadcast(Response, Ratings);
  }
}