
namespace modio
{
  struct GetModfileCall
  {
    const std::function<void(const modio::Response&, const modio::Modfile& modfile)> callback;
  };

  struct GetModfilesCall
  {
    const std::function<void(const modio::Response&, std::vector<modio::Modfile>& modfiles)> callback;
  };

  struct AddModfileCall
  {
    const std::function<void(const modio::Response& response, const modio::Modfile& modfile)> callback;
  };

  struct EditModfileCall
  {
    const std::function<void(const modio::Response& response, const modio::Modfile& modfile)> callback;
  };

  extern std::map<u32, GetModfileCall*> get_modfile_calls;
  extern std::map<u32, GetModfilesCall*> get_modfiles_calls;
  extern std::map<u32, AddModfileCall*> add_modfile_calls;
  extern std::map<u32, EditModfileCall*> edit_modfile_calls;

  void onGetModfile(void* object, ModioResponse modio_response, ModioModfile modfile);
  void onGetModfiles(void* object, ModioResponse modio_response, ModioModfile modfiles[], u32 modfiles_size);
  void onAddModfile(void* object, ModioResponse modio_response, ModioModfile modio_modfile);
  void onEditModfile(void* object, ModioResponse modio_response, ModioModfile modio_modfile);
}
