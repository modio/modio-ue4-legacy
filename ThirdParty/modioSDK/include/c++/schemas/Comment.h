#ifndef MODIO_COMMENT_H
#define MODIO_COMMENT_H

#include "../../c/schemas/ModioComment.h"
#include "User.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
	class Comment
	{
	public:
        u32 id;
        u32 mod_id;
        u32 date_added;
        u32 reply_id;
        i32 karma;
        i32 karma_guest;
        std::string thread_position;
        std::string content;
        User submitted_by;

		void initialize(ModioComment modio_comment);
		json toJson();
	};
}

#endif
