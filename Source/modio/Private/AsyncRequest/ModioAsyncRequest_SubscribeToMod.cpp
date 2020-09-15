// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_SubscribeToMod.h"

FModioAsyncRequest_SubscribeToMod::FModioAsyncRequest_SubscribeToMod( FModioSubsystem *Modio, FModioModDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_SubscribeToMod::Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioMod Mod;
  InitializeMod( Mod, ModioMod );
  
  FModioAsyncRequest_SubscribeToMod* ThisPointer = (FModioAsyncRequest_SubscribeToMod*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, Mod );
  
  ThisPointer->Done();
}