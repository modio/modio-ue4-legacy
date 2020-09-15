// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioModState.generated.h"

UENUM(BlueprintType)
enum EModioModState
{
  NOT_DEFINED                   UMETA(DisplayName = "Undefined"),
  NOT_INSTALLED                 UMETA(DisplayName = "Not installed"),
  QUEUED                        UMETA(DisplayName = "Queued"),
  STARTING_DOWNLOAD             UMETA(DisplayName = "Starting download"),
  DOWNLOADING                   UMETA(DisplayName = "Downloading"),
  PAUSING                       UMETA(DisplayName = "Pausing"),
  PAUSED                        UMETA(DisplayName = "Paused"),
  INSTALLED                     UMETA(DisplayName = "Installed"),
  PRIORITIZING_OTHER_DOWNLOAD   UMETA(DisplayName = "Prioritizing other download"),
  STARTING_UPLOAD               UMETA(DisplayName = "Starting upload"),
  DOWNLOADED                    UMETA(DisplayName = "Downloaded"),
  UPLOADING                     UMETA(DisplayName = "Uploading")
};