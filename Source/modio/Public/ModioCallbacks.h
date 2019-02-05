// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Utility.h"

extern void onEmailRequest(void* object, ModioResponse response);
extern void onEmailExchange(void* object, ModioResponse response);
extern void onModAdded(void *object, ModioResponse response, ModioMod modio_mod);
extern void onGetAllMods(void* object, ModioResponse response, ModioMod* mods, u32 mods_size);
extern void onModEdited(void* object, ModioResponse response, ModioMod modio_mod);
extern void onGetUserSubscriptions(void* object, ModioResponse response, ModioMod* mods, u32 mods_size);
extern void onGetAuthenticatedUser(void* object, ModioResponse response, ModioUser modio_user);