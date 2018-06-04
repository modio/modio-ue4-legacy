
namespace modio
{
  struct DownloadImageCall
  {
    const std::function<void(const modio::Response&)> callback;
  };

  extern std::map<u32, DownloadImageCall*> download_image_calls;

  void onDownloadImage(void* object, ModioResponse modio_response);
}
