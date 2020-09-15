// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_DeleteModDependencies.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DeleteModDependencies::FModioAsyncRequest_DeleteModDependencies( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DeleteModDependencies::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DeleteModDependencies* ThisPointer = (FModioAsyncRequest_DeleteModDependencies*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}