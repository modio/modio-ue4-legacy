// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_EmailRequest.h"

FModioAsyncRequest_EmailRequest::FModioAsyncRequest_EmailRequest( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_EmailRequest::Response( void *Object, ModioResponse ModioResponse )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );
  
  FModioAsyncRequest_EmailRequest* ThisPointer = (FModioAsyncRequest_EmailRequest*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}