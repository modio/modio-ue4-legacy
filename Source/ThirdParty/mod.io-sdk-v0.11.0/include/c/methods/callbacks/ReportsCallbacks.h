#ifndef MODIO_REPORTS_CALLBACKS_H
#define MODIO_REPORTS_CALLBACKS_H

#include "../../../Globals.h"
#include "../../../ModioUtility.h"
#include "../../schemas/ModioResponse.h"

extern std::map< u32, GenericRequestParams* > submit_report_callbacks;

void modioOnSubmitReport(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearReportsCallbackParams();

#endif
