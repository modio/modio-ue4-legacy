// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_OculusAuth.h"

FModioAsyncRequest_OculusAuth::FModioAsyncRequest_OculusAuth( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_OculusAuth::Response( void *Object, ModioResponse ModioResponse )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );
  
  FModioAsyncRequest_OculusAuth* ThisPointer = (FModioAsyncRequest_OculusAuth*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}