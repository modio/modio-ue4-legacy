// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_DownloadModfilesById.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DownloadModfilesById::FModioAsyncRequest_DownloadModfilesById( FModioSubsystem *Modio, FModioBooleanDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DownloadModfilesById::Response(void *Object, ModioResponse ModioResponse, bool ModsAreUpdated)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DownloadModfilesById* ThisPointer = (FModioAsyncRequest_DownloadModfilesById*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ModsAreUpdated );
  
  ThisPointer->Done();
}