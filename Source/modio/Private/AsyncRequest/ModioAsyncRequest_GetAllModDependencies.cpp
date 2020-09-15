// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetAllModDependencies.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAllModDependencies::FModioAsyncRequest_GetAllModDependencies( FModioSubsystem *Modio, FModioModDependencyArrayDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetAllModDependencies::Response(void *Object, ModioResponse ModioResponse, ModioDependency *ModioDependencies, u32 ModioDependenciesSize)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioAsyncRequest_GetAllModDependencies* ThisPointer = (FModioAsyncRequest_GetAllModDependencies*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, ConvertToTArrayModDependencies(ModioDependencies, ModioDependenciesSize) );
  
  ThisPointer->Done();
}