// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_DeleteModSketchfabLinks.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DeleteModSketchfabLinks::FModioAsyncRequest_DeleteModSketchfabLinks( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DeleteModSketchfabLinks::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DeleteModSketchfabLinks* ThisPointer = (FModioAsyncRequest_DeleteModSketchfabLinks*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}