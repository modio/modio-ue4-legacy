#ifndef MODIO_MODIOUTILITY_H
#define MODIO_MODIOUTILITY_H

#include <functional>  // for function
#include <string>      // for string
#include <vector>      // for vector
#include "c/ModioC.h"  // for ModioResponse, u32, ModioFilterCreator, ModioMod
namespace modio { class Response; }

struct GenericRequestParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct GenericCall
{
  const std::function<void(const modio::Response &)> callback;
};

struct GetBoolCall
{
  const std::function<void(const modio::Response &, const bool)> callback;
};

namespace modio
{
  void onUpdateCurrentUser(void *object, ModioResponse response, ModioUser user);
  void onUpdateCurrentUserRatings(void* object, ModioResponse response, ModioRating ratings[], u32 ratings_size);
  void onUpdateCurrentUserSubscriptions(void* object, ModioResponse response, ModioMod mods[], u32 mods_size);
  void handleUnsubscription(u32 mod_id);
  void addModsToDownloadQueue(std::vector<u32> mod_ids);
  void pollUserEvents(u32 poll_time);
  void pollInstalledModsEvents(u32 poll_time);
  void updateAuthenticatedUser(std::string access_token);
  void updateUserRatings();
  void updateUserSubscriptions();
  void addGameIdFilter(ModioFilterCreator &filter);

  // Error handling
  void handleDownloadImageError(void *object, void (*callback)(void *object, ModioResponse modioresponse));
  void processGenericLocalUnauthorizedRequest(void* object, void(*callback)(void* object, ModioResponse response));
  void processLocalUnauthorizedRequestModParam(void* object, void (*callback)(void *object, ModioResponse response, ModioMod mod));
  void processLocalUnauthorizedRequestModfileParam(void* object, void (*callback)(void *object, ModioResponse response, ModioModfile modfile));
  void processLocalUnauthorizedRequestBoolParam(void* object, void (*callback)(void *object, ModioResponse response, bool));
  void processLocalUnauthorizedRequestUserParam(void* object, void (*callback)(void *object, ModioResponse response, ModioUser user));
  void processLocalUnauthorizedRequestModsParam(void* object, void (*callback)(void *object, ModioResponse response, ModioMod mods[], u32 mods_size));
  void processLocalUnauthorizedRequestUserEventsParam(void* object, void (*callback)(void *object, ModioResponse response, ModioUserEvent* events_array, u32 events_array_size));
  void processLocalUnauthorizedRequestGamesParam(void* object, void (*callback)(void *object, ModioResponse response, ModioGame games[], u32 games_size));
  void processLocalUnauthorizedRequestModfilesParam(void* object, void (*callback)(void *object, ModioResponse response, ModioModfile modfiles[], u32 modfiles_size));
  void processLocalUnauthorizedRequestRatingsParam(void* object, void (*callback)(void *object, ModioResponse response, ModioRating ratings[], u32 ratings_size));
}

#endif
