namespace modio
{
  struct SubscribeToModCall
  {
    const std::function<void(const modio::Response&, const modio::Mod& mod)> callback;
  };

  struct UnsubscribeFromModCall
  {
    const std::function<void(const modio::Response&)> callback;
  };

  extern std::map<u32, SubscribeToModCall*> subscribe_to_mod_calls;
  extern std::map<u32, UnsubscribeFromModCall*> unsubscribe_from_mod_calls;

  void onSubscribeToMod(void* object, ModioResponse modio_response, ModioMod mod);
  void onUnsubscribeFromMod(void* object, ModioResponse modio_response);
}
