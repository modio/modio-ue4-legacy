// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_DownloadSubscribedModfiles.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DownloadSubscribedModfiles::FModioAsyncRequest_DownloadSubscribedModfiles( FModioSubsystem *Modio, FModioBooleanDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DownloadSubscribedModfiles::Response(void *Object, ModioResponse ModioResponse, bool ModsAreUpdated)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DownloadSubscribedModfiles* ThisPointer = (FModioAsyncRequest_DownloadSubscribedModfiles*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ModsAreUpdated );
  
  ThisPointer->Done();
}