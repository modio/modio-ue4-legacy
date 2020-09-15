// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_DeleteModYoutubeLinks.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DeleteModYoutubeLinks::FModioAsyncRequest_DeleteModYoutubeLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DeleteModYoutubeLinks::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DeleteModYoutubeLinks* ThisPointer = (FModioAsyncRequest_DeleteModYoutubeLinks*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}