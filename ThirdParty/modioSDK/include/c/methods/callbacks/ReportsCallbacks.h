#ifndef MODIO_REPORTS_CALLBACKS_H
#define MODIO_REPORTS_CALLBACKS_H

#include "../../../Globals.h"
#include "../../schemas/ModioResponse.h"

struct SubmitReportParams
{
	void* object;
	void(*callback)(void* object, ModioResponse response);
};

extern std::map< u32, SubmitReportParams* > submit_report_callbacks;

void modioOnSubmitReport(u32 call_number, u32 response_code, json response_json);

#endif
