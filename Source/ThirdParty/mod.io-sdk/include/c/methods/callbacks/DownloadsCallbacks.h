#ifndef MODIO_DOWNLOADS_CALLBACKS_H
#define MODIO_DOWNLOADS_CALLBACKS_H

#include "../../../Globals.h"
#include "../../../ModioUtility.h"

struct DownloadModfilesByIdParams
{
	void* object;
	u32 call_count;
	bool mods_are_updated;
	void(*callback)(void* object, ModioResponse response, bool mods_are_updated);
};

struct DownloadSubscribedModfilesParams
{
	void* object;
	bool uninstall_unsubscribed;
	std::vector<u32> mod_ids;
	u32 pending_call_count;
	void(*callback)(void* object, ModioResponse response, bool mods_are_updated);
};

extern std::map< u32, DownloadModfilesByIdParams* > download_modfiles_by_id_callbacks;
extern std::map< u32, DownloadSubscribedModfilesParams* > download_subscribed_modfiles_callbacks;

void onModioDownloadModfilesById(void *object, ModioResponse response, ModioMod *mods, u32 mods_size);
void onModioDownloadSubscribedModfiles(void* object, ModioResponse response, ModioMod *mods, u32 mods_size);
void clearDownloadsCallbackParams();

#endif
