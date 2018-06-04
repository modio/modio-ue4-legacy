namespace modio
{
  struct SetDownloadListenerCall
  {
    const std::function<void(u32 response_code, u32 mod_id)> callback;
  };

  struct SetUploadListenerCall
  {
    const std::function<void(u32 response_code, u32 mod_id)> callback;
  };

  extern SetDownloadListenerCall* set_download_listener_call;  
  extern SetUploadListenerCall* set_upload_listener_call;  

  void onDownloadListener(u32 response_code, u32 mod_id);  
  void onUploadListener(u32 response_code, u32 mod_id);  
}