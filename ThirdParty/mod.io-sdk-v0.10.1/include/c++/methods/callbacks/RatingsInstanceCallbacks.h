namespace modio
{
extern std::map<u32, GenericCall *> add_mod_rating_calls;

void onAddModRating(void *object, ModioResponse modio_response);

void clearRatingsRequestCalls();
} // namespace modio
