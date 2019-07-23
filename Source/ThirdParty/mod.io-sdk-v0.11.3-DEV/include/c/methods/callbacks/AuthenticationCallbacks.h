#ifndef MODIO_AUTHENTICATIONCALLBACKS_H
#define MODIO_AUTHENTICATIONCALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"
#include "../../../ModioUtility.h"

extern std::map< u32,GenericRequestParams* > email_request_params;
extern std::map< u32,GenericRequestParams* > email_exchange_params;

void modioOnEmailRequested(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnEmailExchanged(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearAuthenticationCallbackParams();

#endif
