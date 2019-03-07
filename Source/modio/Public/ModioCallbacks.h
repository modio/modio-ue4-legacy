// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"

extern void onModInstalled(u32 response_code, u32 mod_id);
extern void onAddModfile(u32 response_code, u32 mod_id);
extern void onEmailExchange(void* object, ModioResponse modio_response);