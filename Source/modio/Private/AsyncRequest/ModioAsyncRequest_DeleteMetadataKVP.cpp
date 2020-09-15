// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_DeleteMetadataKVP.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DeleteMetadataKVP::FModioAsyncRequest_DeleteMetadataKVP( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DeleteMetadataKVP::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DeleteMetadataKVP* ThisPointer = (FModioAsyncRequest_DeleteMetadataKVP*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}