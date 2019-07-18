namespace modio
{
extern std::map<u32, GenericCall *> galaxy_auth_calls;
extern std::map<u32, GenericCall *> steam_auth_calls;
extern std::map<u32, GenericCall *> steam_auth_encoded_calls;
extern std::map<u32, GenericCall *> link_external_account_calls;

void onGalaxyAuth(void *object, ModioResponse modio_response);
void onSteamAuth(void *object, ModioResponse modio_response);
void onSteamAuthEncoded(void *object, ModioResponse modio_response);
void onLinkExternalAccount(void *object, ModioResponse modio_response);

void clearExternalAuthenticationRequestCalls();
} // namespace modio
