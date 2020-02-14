// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_CheckIfModsAreUpdated.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_CheckIfModsAreUpdated::FModioAsyncRequest_CheckIfModsAreUpdated( FModioSubsystem *Modio, FModioBooleanDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_CheckIfModsAreUpdated::Response(void *Object, ModioResponse ModioResponse, bool ModsAreUpdated)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_CheckIfModsAreUpdated* ThisPointer = (FModioAsyncRequest_CheckIfModsAreUpdated*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ModsAreUpdated );
  
  ThisPointer->Done();
}