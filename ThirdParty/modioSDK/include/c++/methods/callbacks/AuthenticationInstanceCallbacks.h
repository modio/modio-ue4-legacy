
namespace modio
{
  struct EmailRequestCall
  {
    const std::function<void(const modio::Response&)> callback;
  };

  struct EmailExchangeCall
  {
    const std::function<void(const modio::Response&)> callback;
  };

  extern std::map<u32, EmailRequestCall*> email_request_calls;
  extern std::map<u32, EmailExchangeCall*> email_exchange_calls;

  void onEmailRequest(void* object, ModioResponse modio_response);
  void onEmailExchange(void* object, ModioResponse modio_response);
}
