// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetUserSubscriptions.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetUserSubscriptions::FModioAsyncRequest_GetUserSubscriptions( FModioSubsystem *Modio, FModioModArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetUserSubscriptions::Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetUserSubscriptions* ThisPointer = (FModioAsyncRequest_GetUserSubscriptions*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayMods(ModioMods, ModioModsSize) );
  
  ThisPointer->Done();
}