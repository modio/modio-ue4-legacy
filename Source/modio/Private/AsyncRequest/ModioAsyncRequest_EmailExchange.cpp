#include "AsyncRequest/ModioAsyncRequest_EmailExchange.h"

FModioAsyncRequest_EmailExchange::FModioAsyncRequest_EmailExchange( FModioSubsystem *Modio, FEmailExchangeDelegate Delegate ) :
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