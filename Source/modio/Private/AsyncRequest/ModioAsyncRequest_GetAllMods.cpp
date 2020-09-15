// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetAllMods.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAllMods::FModioAsyncRequest_GetAllMods( FModioSubsystem *Modio, FModioModArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetAllMods::Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetAllMods* ThisPointer = (FModioAsyncRequest_GetAllMods*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayMods(ModioMods, ModioModsSize) );
  
  ThisPointer->Done();
}