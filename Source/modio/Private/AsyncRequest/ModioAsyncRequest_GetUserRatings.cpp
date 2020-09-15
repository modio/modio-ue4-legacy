// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetUserRatings.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetUserRatings::FModioAsyncRequest_GetUserRatings( FModioSubsystem *Modio, FModioRatingArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetUserRatings::Response(void *Object, ModioResponse ModioResponse, ModioRating *ModioRatings, u32 ModioRatingsSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetUserRatings* ThisPointer = (FModioAsyncRequest_GetUserRatings*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayRatings(ModioRatings, ModioRatingsSize) );
  
  ThisPointer->Done();
}