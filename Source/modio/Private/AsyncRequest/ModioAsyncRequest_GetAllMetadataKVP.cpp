// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetAllMetadataKVP.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAllMetadataKVP::FModioAsyncRequest_GetAllMetadataKVP( FModioSubsystem *Modio, FModioMetadataKVPArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetAllMetadataKVP::Response(void *Object, ModioResponse ModioResponse, ModioMetadataKVP *ModioMetadataKVP, u32 ModioMetadataKVPize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetAllMetadataKVP* ThisPointer = (FModioAsyncRequest_GetAllMetadataKVP*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayMetadataKVP(ModioMetadataKVP, ModioMetadataKVPize) );
  
  ThisPointer->Done();
}