// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetUserMods.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetUserMods::FModioAsyncRequest_GetUserMods( FModioSubsystem *Modio, FModioModArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetUserMods::Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetUserMods* ThisPointer = (FModioAsyncRequest_GetUserMods*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayMods(ModioMods, ModioModsSize) );
  
  ThisPointer->Done();
}