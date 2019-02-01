// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Runtime/Core/Public/Modules/ModuleManager.h"

#include "Schemas/FModioAvatar.h"
#include "Schemas/FModioDownload.h"
#include "Schemas/FModioFilehash.h"
#include "Schemas/FModioImage.h"
#include "Schemas/FModioInstalledMod.h"
#include "Schemas/FModioLogo.h"
#include "Schemas/FModioMedia.h"
#include "Schemas/FModioMetadataKVP.h"
#include "Schemas/FModioMod.h"
#include "Schemas/FModioModfile.h"
#include "Schemas/FModioQueuedModDownload.h"
#include "Schemas/FModioQueuedModfileUpload.h"
#include "Schemas/FModioStats.h"
#include "Schemas/FModioTag.h"
#include "Schemas/FModioUser.h"

#include "Customizables/FModioModCreator.h"
#include "Customizables/FModioModEditor.h"
#include "Customizables/FModioModfileCreator.h"

#include "ModioSchemas.generated.h"

UENUM(BlueprintType)
namespace ModioFilterEnum
{
enum Type
{
  SORT_BY_ID UMETA(DisplayName = "Sort by id"),
  SORT_BY_RATING UMETA(DisplayName = "Sort by rating"),
  SORT_BY_DATE_LIVE UMETA(DisplayName = "Sort by date live"),
  SORT_BY_DATE_UPDATED UMETA(DisplayName = "Sort by date updated")
};
}