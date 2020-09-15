// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_EditMod.h"

FModioAsyncRequest_EditMod::FModioAsyncRequest_EditMod( FModioSubsystem *Modio, FModioModDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_EditMod::Response( void *Object, ModioResponse ModioResponse, ModioMod ModioMod )
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioMod Mod;
  InitializeMod( Mod, ModioMod );
  
  FModioAsyncRequest_EditMod* ThisPointer = (FModioAsyncRequest_EditMod*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, Mod );
  
  ThisPointer->Done();
}