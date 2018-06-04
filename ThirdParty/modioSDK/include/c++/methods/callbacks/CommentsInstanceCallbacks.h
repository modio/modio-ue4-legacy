
namespace modio
{
	struct GetAllModCommentsCall
	{
		const std::function<void(const modio::Response& response, const std::vector<modio::Comment> & comment)> callback;
	};

	struct DeleteModCommentCall
	{
		const std::function<void(const modio::Response& response)> callback;
	};

	extern std::map<u32, GetAllModCommentsCall*> get_all_mod_comments_calls;
	extern std::map<u32, DeleteModCommentCall*> delete_mod_comment_calls;

	void onGetAllModComments(void* object, ModioResponse response, ModioComment* comments_array, u32 comments_array_size);
	void onDeleteModComment(void* object, ModioResponse response);
}
