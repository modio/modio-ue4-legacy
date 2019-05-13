#include "AsyncRequest/ModioAsyncRequest_AddMetadataKVPs.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_AddMetadataKVPs::FModioAsyncRequest_AddMetadataKVPs( FModioSubsystem *Modio, FModioGenericDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_AddMetadataKVPs::Response(void *Object, ModioResponse ModioResponse)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_AddMetadataKVPs* ThisPointer = (FModioAsyncRequest_AddMetadataKVPs*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
  
  ThisPointer->Done();
}