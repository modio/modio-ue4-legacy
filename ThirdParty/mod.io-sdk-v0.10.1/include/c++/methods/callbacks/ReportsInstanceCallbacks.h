namespace modio
{
extern std::map<u32, GenericCall *> submit_report_calls;

void onSubmitReport(void *object, ModioResponse modio_response);

void clearReportsRequestCalls();
} // namespace modio
