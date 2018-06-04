
namespace modio
{
  struct GetMetadataKVPCall
  {
    const std::function<void(const modio::Response& response, std::vector<modio::MetadataKVP> metadata_kvp)> callback;
  };

  struct AddMetadataKVPCall
  {
    char** metadata_kvp_array;
    u32 metadata_kvp_array_size;
    const std::function<void(const modio::Response& response)> callback;
  };

  struct DeleteMetadataKVPCall
  {
    char** metadata_kvp_array;
    u32 metadata_kvp_array_size;
    const std::function<void(const modio::Response& response)> callback;
  };

  extern std::map<u32, GetMetadataKVPCall*> get_metadata_kvp_calls;
  extern std::map<u32, AddMetadataKVPCall*> add_metadata_kvp_calls;
  extern std::map<u32, DeleteMetadataKVPCall*> delete_metadata_kvp_calls;

  void onGetMetadataKVP(void* object, ModioResponse modio_response, ModioMetadataKVP* metadata_kvp_array, u32 metadata_kvp_array_size);
  void onAddMetadataKVP(void* object, ModioResponse modio_response);
  void onDeleteMetadataKVP(void* object, ModioResponse modio_response);
}
