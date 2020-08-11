// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once
#include "AsyncRequest/ModioAsyncRequest.h"
#include "Schemas/ModioResponse.h"
#include "Schemas/ModioRating.h"

/**
* Callback returning all the ratings submited by the authtenticated user
* @param ModioResponse - Response from Modio backend
* @param Ratings - Rating submited by the authtenticated user to mod.io
*/

class FModioAsyncRequest_GetUserRatings : public FModioAsyncRequest
{
public:
  static void Response(void *Object, ModioResponse ModioResponse, ModioRating *ModioRatings, u32 ModioRatingsSize);

protected:
  FModioAsyncRequest_GetUserRatings( FModioSubsystem* Modio, FModioRatingArrayDelegate Delegate );

  /** This should be the only way to create and queue async requests */
  template<typename RequestType, typename CallbackType>
  friend RequestType* CreateAsyncRequest( FModioSubsystem* Subsystem, CallbackType CallbackDelegate );
private:
  FModioRatingArrayDelegate ResponseDelegate;
};