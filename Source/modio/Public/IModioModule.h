// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Modules/ModuleInterface.h"
#include "ModioSubsystem.h"

DECLARE_LOG_CATEGORY_EXTERN( LogModio, Log, All );

/**
 * Barbone inteface, so we don't bloat compile times when we update the implementation details
 */
class IModioModule : public IModuleInterface
{
  /** Returns the subsystem associated with the world, might be null */
  static FModioSubsystemPtr Get(UWorld* world);
};
