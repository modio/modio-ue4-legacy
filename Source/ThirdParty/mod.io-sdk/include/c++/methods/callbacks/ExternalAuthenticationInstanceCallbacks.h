#include "../../ModioUtility.h"
#include <map>

namespace modio
{
class Terms;

struct GetTermsCall
{
  const std::function<void(const modio::Response&, const modio::Terms&)> callback;
};

extern std::map<u32, GenericCall *> galaxy_auth_calls;
extern std::map<u32, GenericCall *> oculus_auth_calls;
extern std::map<u32, GenericCall *> steam_auth_calls;
extern std::map<u32, GenericCall *> steam_auth_encoded_calls;
extern std::map<u32, GenericCall *> link_external_account_calls;
extern std::map<u32, GetTermsCall*> get_terms_calls;

void onGalaxyAuth(void *object, ModioResponse modio_response);
void onOculusAuth(void *object, ModioResponse modio_response);
void onSteamAuth(void *object, ModioResponse modio_response);
void onSteamAuthEncoded(void *object, ModioResponse modio_response);
void onLinkExternalAccount(void *object, ModioResponse modio_response);
void onGetTerms(void* object, ModioResponse modio_response, ModioTerms* modio_terms);

void clearExternalAuthenticationRequestCalls();
} // namespace modio
