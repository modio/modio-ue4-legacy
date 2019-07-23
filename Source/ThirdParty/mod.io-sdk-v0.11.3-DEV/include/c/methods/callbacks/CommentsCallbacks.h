#ifndef MODIO_COMMENTS_CALLBACKS_H
#define MODIO_COMMENTS_CALLBACKS_H

#include "../../../Globals.h"
#include "../../../ModioUtility.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioComment.h"

struct GetAllModCommentsParams
{
	void* object;
	std::string url;
	bool is_cache;
	void (*callback)(void* object, ModioResponse response, ModioComment comments[], u32 comments_size);
};

struct GetModCommentParams
{
	void* object;
	void(*callback)(void* object, ModioResponse response, ModioComment comment);
};

extern std::map< u32, GetAllModCommentsParams* > get_all_mod_comments_callbacks;
extern std::map< u32, GetModCommentParams* > get_mod_comment_callbacks;
extern std::map< u32, GenericRequestParams* > delete_mod_comment_callbacks;

void modioOnGetAllModComments(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnGetModComment(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnDeleteModComment(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearCommentsCallbackParams();

#endif
