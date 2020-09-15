// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#ifdef MODIO_UE4_WINDOWS_BUILD
  #include "Windows/PreWindowsApi.h"
#endif
#ifndef STRICT
#define STRICT
#endif
#include "c/ModioC.h"
#ifdef MODIO_UE4_WINDOWS_BUILD
  #include "Windows/PostWindowsApi.h"
#endif
