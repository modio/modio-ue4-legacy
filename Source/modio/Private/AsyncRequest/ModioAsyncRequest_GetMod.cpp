// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetMod.h"

FModioAsyncRequest_GetMod::FModioAsyncRequest_GetMod( FModioSubsystem *Modio, FModioModDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetMod::Response(void *Object, ModioResponse ModioResponse, ModioMod ModioMod )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioMod Mod;
  InitializeMod( Mod, ModioMod );

  FModioAsyncRequest_GetMod* ThisPointer = (FModioAsyncRequest_GetMod*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, Mod );
  
  ThisPointer->Done();
}