namespace modio
{
  struct GetAuthenticatedUserCall
  {
    const std::function<void(const modio::Response&, const modio::User& user)> callback;
  };

  struct GetUserSubscriptionsCall
  {
    const std::function<void(const modio::Response& response, const std::vector<modio::Mod> & mods)> callback;
  };

  struct GetUserEventsCall
  {
    const std::function<void(const modio::Response& response, std::vector<modio::Event> events)> callback;
  };

  struct GetUserGamesCall
  {
    const std::function<void(const modio::Response& response, const std::vector<modio::Game> & games)> callback;
  };

  struct GetUserModsCall
  {
    const std::function<void(const modio::Response& response, const std::vector<modio::Mod> & mods)> callback;
  };

  struct GetUserModfilesCall
  {
    const std::function<void(const modio::Response& response, const std::vector<modio::Modfile> & modfiles)> callback;
  };

  extern std::map<u32, GetAuthenticatedUserCall*> get_authenticated_user_calls;
  extern std::map<u32, GetUserSubscriptionsCall*> get_user_subscriptions_calls;
  extern std::map<u32, GetUserEventsCall*> get_user_events_calls;
  extern std::map<u32, GetUserGamesCall*> get_user_games_calls;
  extern std::map<u32, GetUserModsCall*> get_user_mods_calls;
  extern std::map<u32, GetUserModfilesCall*> get_user_modfiles_calls;

  void onGetAuthenticatedUser(void* object, ModioResponse modio_response, ModioUser modio_user);
  void onGetUserSubscriptions(void* object, ModioResponse modio_response, ModioMod mods[], u32 mods_size);
  void onGetUserEvents(void* object, ModioResponse modio_response, ModioEvent* events_array, u32 events_array_size);
  void onGetUserGames(void* object, ModioResponse modio_response, ModioGame games[], u32 games_size);
  void onGetUserMods(void* object, ModioResponse modio_response, ModioMod mods[], u32 mods_size);
  void onGetUserModfiles(void* object, ModioResponse modio_response, ModioModfile modfiles[], u32 modfiles_size);
}
