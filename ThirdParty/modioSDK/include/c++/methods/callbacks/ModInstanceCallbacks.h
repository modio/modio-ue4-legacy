
namespace modio
{
  struct GetModCall
  {
    const std::function<void(const modio::Response&, const modio::Mod& mod)> callback;
  };

  struct GetModsCall
  {
    const std::function<void(const modio::Response&, std::vector<modio::Mod>& mods)> callback;
  };

  struct AddModCall
  {
    const std::function<void(const modio::Response& response, const modio::Mod& mod)> callback;
  };

  struct EditModCall
  {
    const std::function<void(const modio::Response& response, const modio::Mod& mod)> callback;
  };

  struct DeleteModCall
  {
    const std::function<void(const modio::Response& response)> callback;
  };

  extern std::map<u32, GetModCall*> get_mod_calls;
  extern std::map<u32, GetModsCall*> get_mods_calls;
  extern std::map<u32, AddModCall*> add_mod_calls;
  extern std::map<u32, EditModCall*> edit_mod_calls;
  extern std::map<u32, DeleteModCall*> delete_mod_calls;

  void onGetMod(void* object, ModioResponse modio_response, ModioMod mod);
  void onGetMods(void* object, ModioResponse modio_response, ModioMod mods[], u32 mods_size);
  void onAddMod(void* object, ModioResponse modio_response, ModioMod mod);
  void onEditMod(void* object, ModioResponse modio_response, ModioMod mod);
  void onDeleteMod(void* object, ModioResponse modio_response);
}
