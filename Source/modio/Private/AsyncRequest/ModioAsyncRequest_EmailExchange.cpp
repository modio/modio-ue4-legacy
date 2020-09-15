// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_EmailExchange.h"

FModioAsyncRequest_EmailExchange::FModioAsyncRequest_EmailExchange( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_EmailExchange::Response( void *Object, ModioResponse ModioResponse )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );
  
  FModioAsyncRequest_EmailExchange* ThisPointer = (FModioAsyncRequest_EmailExchange*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}