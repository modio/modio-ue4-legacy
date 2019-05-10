#include "AsyncRequest/ModioAsyncRequest_GetAllModTags.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAllModTags::FModioAsyncRequest_GetAllModTags( FModioSubsystem *Modio, FModioModTagsArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetAllModTags::Response(void *Object, ModioResponse ModioResponse, ModioTag *ModioTags, u32 ModioTagsSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetAllModTags* ThisPointer = (FModioAsyncRequest_GetAllModTags*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayModTags(ModioTags, ModioTagsSize) );
  
  ThisPointer->Done();
}