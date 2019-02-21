// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "ModioUE4Utility.h"
#include "UModioComponent.h"

extern void onGetAuthenticatedUser(void* object, ModioResponse response, ModioUser modio_user);
extern void onModInstalled(u32 response_code, u32 mod_id);
extern void onAddModfile(u32 response_code, u32 mod_id);