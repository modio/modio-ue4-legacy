#include "../../ModioUtility.h"
#include "../../schemas/Comment.h"
#include <map>

namespace modio
{
struct GetAllModCommentsCall
{
  const std::function<void(const modio::Response &response, const std::vector<modio::Comment> &comment)> callback;
};

struct GetModCommentCall
{
  const std::function<void(const modio::Response &response, modio::Comment &comment)> callback;
};

extern std::map<u32, GetAllModCommentsCall *> get_all_mod_comments_calls;
extern std::map<u32, GetModCommentCall *> get_mod_comment_calls;
extern std::map<u32, GenericCall *> delete_mod_comment_calls;

void onGetAllModComments(void *object, ModioResponse response, ModioComment *comments_array, u32 comments_array_size);
void onGetModComment(void *object, ModioResponse response, ModioComment comment);
void onDeleteModComment(void *object, ModioResponse response);

void clearCommentsRequestCalls();
} // namespace modio
