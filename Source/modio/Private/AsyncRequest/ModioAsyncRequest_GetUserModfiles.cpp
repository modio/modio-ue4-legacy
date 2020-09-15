// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetUserModfiles.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetUserModfiles::FModioAsyncRequest_GetUserModfiles( FModioSubsystem *Modio, FModioModfileArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetUserModfiles::Response(void *Object, ModioResponse ModioResponse, ModioModfile *ModioModfiles, u32 ModioModfilesSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetUserModfiles* ThisPointer = (FModioAsyncRequest_GetUserModfiles*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayModfiles(ModioModfiles, ModioModfilesSize) );
  
  ThisPointer->Done();
}