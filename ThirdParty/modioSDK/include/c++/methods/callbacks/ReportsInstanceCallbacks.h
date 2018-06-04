namespace modio
{
  struct SubmitReportCall
  {
    const std::function<void(const modio::Response&)> callback;
  };

  extern std::map<u32, SubmitReportCall*> submit_report_calls;

  void onSubmitReport(void* object, ModioResponse modio_response);
}
