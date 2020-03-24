#ifndef MODIO_DOWNLOADS_CALLBACKS_H
#define MODIO_DOWNLOADS_CALLBACKS_H

#include "../../../Globals.h"
#include "../../../ModioUtility.h"

struct CheckIfModsAreUpdatedParams
{
	void* object;
	void(*callback)(void* object, ModioResponse response, bool mods_are_updated);
};

extern std::map< u32, CheckIfModsAreUpdatedParams* > check_if_mods_are_updated_callbacks;

void onModioCheckIfModsAreUpdated(void *object, ModioResponse response, ModioMod *mods, u32 mods_size);
void clearDownloadsCallbackParams();

#endif
