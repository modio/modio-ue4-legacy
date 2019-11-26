#ifndef MODIO_EXTERNALAUTHENTICATIONCALLBACKS_H
#define MODIO_EXTERNALAUTHENTICATIONCALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"
#include "../../../ModioUtility.h"

extern std::map< u32,GenericRequestParams* > galaxy_auth_params;
extern std::map< u32,GenericRequestParams* > oculus_auth_params;
extern std::map< u32,GenericRequestParams* > steam_auth_params;
extern std::map< u32,GenericRequestParams* > steam_auth_encoded_params;
extern std::map< u32,GenericRequestParams* > link_external_account_params;

void modioOnGalaxyAuth(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnOculusAuth(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnSteamAuth(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnSteamAuthEncoded(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnLinkExternalAccount(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearExternalAuthenticationCallbackParams();

#endif
