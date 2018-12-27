namespace modio
{
struct GetAllModDependenciesCall
{
  const std::function<void(const modio::Response &response, const std::vector<modio::Dependency> &mods)> callback;
};

extern std::map<u32, GetAllModDependenciesCall *> get_all_mod_dependencies_calls;
extern std::map<u32, GenericCall *> add_mod_dependencies_calls;
extern std::map<u32, GenericCall *> delete_mod_dependencies_calls;

void onGetAllModDependencies(void *object, ModioResponse response, ModioDependency *dependencies_array, u32 dependencies_array_size);
void onAddModDependencies(void *object, ModioResponse response);
void onDeleteModDependencies(void *object, ModioResponse response);

void clearDependenciesRequestCalls();
} // namespace modio
