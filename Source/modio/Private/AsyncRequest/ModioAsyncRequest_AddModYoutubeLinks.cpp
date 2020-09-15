// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_AddModYoutubeLinks.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_AddModYoutubeLinks::FModioAsyncRequest_AddModYoutubeLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_AddModYoutubeLinks::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_AddModYoutubeLinks* ThisPointer = (FModioAsyncRequest_AddModYoutubeLinks*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}