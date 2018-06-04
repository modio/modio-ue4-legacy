namespace modio
{
  struct AddModRatingCall
  {
    const std::function<void(const modio::Response&)> callback;
  };

  extern std::map<u32, AddModRatingCall*> add_mod_rating_calls;

  void onAddModRating(void* object, ModioResponse modio_response);
}
