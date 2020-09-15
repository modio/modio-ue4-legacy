// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioModDependency.h"

void InitializeModDependency(FModioModDependency &ModDependency, const ModioDependency &ModioModDependency)
{
  ModDependency.ModId = ModioModDependency.mod_id;
  ModDependency.DateAdded = ModioModDependency.date_added;
}