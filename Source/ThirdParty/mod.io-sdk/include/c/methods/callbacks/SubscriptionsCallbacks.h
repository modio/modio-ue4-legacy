#ifndef MODIO_SUBSCRIPTIONSCALLBACKS_H
#define MODIO_SUBSCRIPTIONSCALLBACKS_H

#include "../../../Globals.h"
#include "../../../wrappers/MinizipWrapper.h"
#include "../../../wrappers/CurlWrapper.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioMod.h"
#include "../../../ModUtility.h"
#include "../../../ModioUtility.h"

struct SubscribeToModParams
{
  void* object;
  u32 mod_id;
  void (*callback)(void* object, ModioResponse response, ModioMod mod);
};

struct UnsubscribeFromModParams
{
  void* object;
  u32 mod_id;
  void (*callback)(void* object, ModioResponse response);
};

extern std::map< u32, SubscribeToModParams* > subscribe_to_mod_callbacks;
extern std::map< u32, UnsubscribeFromModParams* > unsubscribe_from_mod_callbacks;

void modioOnSubscribeToMod(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnUnsubscribeFromMod(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearSubscriptionsCallbackParams();

#endif
