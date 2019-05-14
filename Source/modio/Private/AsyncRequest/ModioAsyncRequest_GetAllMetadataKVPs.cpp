#include "AsyncRequest/ModioAsyncRequest_GetAllMetadataKVPs.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAllMetadataKVPs::FModioAsyncRequest_GetAllMetadataKVPs( FModioSubsystem *Modio, FModioMetadataKVPArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetAllMetadataKVPs::Response(void *Object, ModioResponse ModioResponse, ModioMetadataKVP *ModioMetadataKVPs, u32 ModioMetadataKVPSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetAllMetadataKVPs* ThisPointer = (FModioAsyncRequest_GetAllMetadataKVPs*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayMetadataKVPs(ModioMetadataKVPs, ModioMetadataKVPSize) );
  
  ThisPointer->Done();
}