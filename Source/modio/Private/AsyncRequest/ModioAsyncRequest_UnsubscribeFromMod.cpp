// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_UnsubscribeFromMod.h"

FModioAsyncRequest_UnsubscribeFromMod::FModioAsyncRequest_UnsubscribeFromMod( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_UnsubscribeFromMod::Response( void *Object, ModioResponse ModioResponse )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );
  
  FModioAsyncRequest_UnsubscribeFromMod* ThisPointer = (FModioAsyncRequest_UnsubscribeFromMod*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}