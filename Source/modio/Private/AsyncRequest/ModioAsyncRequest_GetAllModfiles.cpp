// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetAllModfiles.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAllModfiles::FModioAsyncRequest_GetAllModfiles(FModioSubsystem* Modio, FModioModfileArrayDelegate Delegate) :
  FModioAsyncRequest(Modio),
  ResponseDelegate(Delegate)
{
}

void FModioAsyncRequest_GetAllModfiles::Response(void* Object, ModioResponse InResponse, ModioModfile* Modfiles, u32 ModfilesSize)
{
  FModioResponse Response;
  InitializeResponse(Response, InResponse);
  FModioAsyncRequest_GetAllModfiles* ThisPointer = (FModioAsyncRequest_GetAllModfiles*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound(Response, ConvertToTArrayModfiles(Modfiles, ModfilesSize));

  ThisPointer->Done();
}