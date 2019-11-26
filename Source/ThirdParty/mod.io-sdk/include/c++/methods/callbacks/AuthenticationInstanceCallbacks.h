#include "../../ModioUtility.h"
#include <map>

namespace modio
{
extern std::map<u32, GenericCall *> email_request_calls;
extern std::map<u32, GenericCall *> email_exchange_calls;

void onEmailRequest(void *object, ModioResponse modio_response);
void onEmailExchange(void *object, ModioResponse modio_response);

void clearAuthenticationRequestCalls();
} // namespace modio
