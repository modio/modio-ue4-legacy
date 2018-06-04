#ifndef MODIO_AUTHENTICATIONCALLBACKS_H
#define MODIO_AUTHENTICATIONCALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"

struct EmailRequestParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct EmailExchangeParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

extern std::map< u32,EmailRequestParams* > email_request_params;
extern std::map< u32,EmailExchangeParams* > email_exchange_params;

void modioOnEmailRequested(u32 call_number, u32 response_code, json response_json);
void modioOnEmailExchanged(u32 call_number, u32 response_code, json response_json);

#endif
