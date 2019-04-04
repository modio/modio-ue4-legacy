namespace modio
{
struct GetModStatsCall
{
  const std::function<void(const modio::Response &, const modio::Stats &stats)> callback;
};

struct GetAllModStatsCall
{
  const std::function<void(const modio::Response &, std::vector<modio::Stats> &mods_stats)> callback;
};

extern std::map<u32, GetModStatsCall *> get_mod_stats_calls;
extern std::map<u32, GetAllModStatsCall *> get_all_mod_stats_calls;

void onGetModStats(void *object, ModioResponse modio_response, ModioStats stats);
void onGetAllModStats(void *object, ModioResponse modio_response, ModioStats mods_stats[], u32 mods_stats_size);

void clearModStatsRequestCalls();
} // namespace modio
