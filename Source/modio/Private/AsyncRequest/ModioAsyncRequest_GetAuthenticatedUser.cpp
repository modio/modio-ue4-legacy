// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_GetAuthenticatedUser.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_GetAuthenticatedUser::FModioAsyncRequest_GetAuthenticatedUser( FModioSubsystem *Modio, FModioUserDelegate Delegate ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
}

void FModioAsyncRequest_GetAuthenticatedUser::Response(void *Object, ModioResponse ModioResponse, ModioUser ModioUser)
{
  FModioResponse Response;
  InitializeResponse( Response, ModioResponse );

  FModioUser User;
  InitializeUser( User, ModioUser );

  FModioAsyncRequest_GetAuthenticatedUser* ThisPointer = (FModioAsyncRequest_GetAuthenticatedUser*)Object;
  ThisPointer->ResponseDelegate.ExecuteIfBound( Response, User );
  
  ThisPointer->Done();
}