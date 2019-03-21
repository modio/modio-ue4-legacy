#include "AsyncRequest/ModioAsyncRequest_EmailRequest.h"

FModioAsyncRequest_EmailRequest::FModioAsyncRequest_EmailRequest( FModioSubsystem *Modio, FEmailRequestDelegate Delegate ) :
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