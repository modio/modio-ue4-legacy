#include "../../ModioUtility.h"
#include <map>
#include "../../schemas/ModEvent.h"

namespace modio
{
struct GetEventsCall
{
  const std::function<void(const modio::Response &response, std::vector<modio::ModEvent> events)> callback;
};

struct GetAllEventsCall
{
  const std::function<void(const modio::Response &response, std::vector<modio::ModEvent> events)> callback;
};

struct SetEventListenerCall
{
  const std::function<void(const modio::Response &response, std::vector<modio::ModEvent> events)> callback;
};

extern std::map<u32, GetEventsCall *> get_events_calls;
extern std::map<u32, GetAllEventsCall *> get_all_events_calls;
extern SetEventListenerCall *set_event_listener_call;

void onGetEvents(void *object, ModioResponse modio_response, ModioModEvent *events_array, u32 events_array_size);
void onGetAllEvents(void *object, ModioResponse modio_response, ModioModEvent *events_array, u32 events_array_size);
void onSetEventListener(ModioResponse modio_response, ModioModEvent *events_array, u32 events_array_size);

void clearModEventsRequestCalls();
} // namespace modio
