#ifndef MODIO_MECALLBACKS_H
#define MODIO_MECALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioUser.h"
#include "../../schemas/ModioMod.h"
#include "../../schemas/ModioGame.h"
#include "../../schemas/ModioEvent.h"
#include "../../../Globals.h"
#include "../../../ModUtility.h"

struct GetAuthenticatedUserParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioUser user);
};

struct GetUserSubscriptionsParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size);
};

struct GetUserEventsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size);
};

struct GetUserGamesParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioGame games[], u32 games_size);
};

struct GetUserModsParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size);
};

struct GetUserModfilesParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioModfile modfiles[], u32 modfiles_size);
};

extern std::map< u32, GetAuthenticatedUserParams* > get_authenticated_user_callbacks;
extern std::map< u32, GetUserSubscriptionsParams* > get_user_subscriptions_callbacks;
extern std::map< u32, GetUserEventsParams* > get_user_events_callbacks;
extern std::map< u32, GetUserGamesParams* > get_user_games_callbacks;
extern std::map< u32, GetUserModsParams* > get_user_mods_callbacks;
extern std::map< u32, GetUserModfilesParams* > get_user_modfiles_callbacks;

void modioOnGetAuthenticatedUser(u32 call_number, u32 response_code, json response_json);
void modioOnGetUserSubscriptions(u32 call_number, u32 response_code, json response_json);
void modioOnGetUserEvents(u32 call_number, u32 response_code, json response_json);
void modioOnGetUserMods(u32 call_number, u32 response_code, json response_json);
void modioOnGetUserGames(u32 call_number, u32 response_code, json response_json);
void modioOnGetUserModfiles(u32 call_number, u32 response_code, json response_json);

#endif
