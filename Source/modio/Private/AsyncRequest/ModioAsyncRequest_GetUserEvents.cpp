// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetUserEvents.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetUserEvents::FModioAsyncRequest_GetUserEvents( FModioSubsystem *Modio, FModioUserEventArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetUserEvents::Response(void *Object, ModioResponse ModioResponse, ModioUserEvent *ModioUserEvents, u32 ModioUserEventsSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetUserEvents* ThisPointer = (FModioAsyncRequest_GetUserEvents*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayUserEvents(ModioUserEvents, ModioUserEventsSize) );
  
  ThisPointer->Done();
}