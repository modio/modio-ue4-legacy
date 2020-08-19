#ifndef MODIO_GAME_CALLBACKS_H
#define MODIO_GAME_CALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../ModioUtility.h"
#include "../../schemas/ModioGame.h"

struct GetGameParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioGame game);
};

extern std::map< u32, GetGameParams* > get_game_callbacks;

void modioOnGetGame( u32 call_number, u32 response_code, nlohmann::json response_json );

void clearGameCallbackParams();

#endif