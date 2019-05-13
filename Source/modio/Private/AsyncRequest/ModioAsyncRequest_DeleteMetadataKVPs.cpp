#include "AsyncRequest/ModioAsyncRequest_DeleteMetadataKVPs.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_DeleteMetadataKVPs::FModioAsyncRequest_DeleteMetadataKVPs( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_DeleteMetadataKVPs::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_DeleteMetadataKVPs* ThisPointer = (FModioAsyncRequest_DeleteMetadataKVPs*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}