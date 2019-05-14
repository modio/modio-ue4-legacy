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
  FModioAsyncRequest_GetUserRatings( FModioSubsystem *Modio, FModioRatingArrayDelegate Delegate );

  static void Response(void *Object, ModioResponse ModioResponse, ModioRating *ModioRatings, u32 ModioRatingsSize);

private:
  FModioRatingArrayDelegate ResponseDelegate;
};