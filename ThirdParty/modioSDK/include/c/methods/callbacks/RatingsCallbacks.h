#ifndef MODIO_RATINGSCALLBACKS_H
#define MODIO_RATINGSCALLBACKS_H

#include "../../../Globals.h"
#include "../../../wrappers/MinizipWrapper.h"
#include "../../../wrappers/CurlWrapper.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioMod.h"
#include "../../../ModUtility.h"

struct AddModRatingParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

extern std::map< u32, AddModRatingParams* > add_mod_rating_callbacks;

void modioOnAddModRating(u32 call_number, u32 response_code, json response_json);

#endif
