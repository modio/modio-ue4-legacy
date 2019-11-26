#include "../../ModioUtility.h"
#include <map>
#include "../../schemas/Mod.h"

namespace modio
{
struct GetModCall
{
  const std::function<void(const modio::Response &, const modio::Mod &mod)> callback;
};

struct GetAllModsCall
{
  const std::function<void(const modio::Response &, std::vector<modio::Mod> &mods)> callback;
};

struct AddModCall
{
  const std::function<void(const modio::Response &response, const modio::Mod &mod)> callback;
};

struct EditModCall
{
  const std::function<void(const modio::Response &response, const modio::Mod &mod)> callback;
};

extern std::map<u32, GetModCall *> get_mod_calls;
extern std::map<u32, GetAllModsCall *> get_all_mods_calls;
extern std::map<u32, AddModCall *> add_mod_calls;
extern std::map<u32, EditModCall *> edit_mod_calls;
extern std::map<u32, GenericCall *> delete_mod_calls;

void onGetMod(void *object, ModioResponse modio_response, ModioMod mod);
void onGetAllMods(void *object, ModioResponse modio_response, ModioMod mods[], u32 mods_size);
void onAddMod(void *object, ModioResponse modio_response, ModioMod mod);
void onEditMod(void *object, ModioResponse modio_response, ModioMod mod);
void onDeleteMod(void *object, ModioResponse modio_response);

void clearModRequestCalls();
} // namespace modio
