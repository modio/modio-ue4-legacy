// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioCallbacks.h"
#include "ModioComponent.h"

void onModInstalled(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModDownloadDelegate.Broadcast((int32)response_code, (int32)mod_id);
}

void onAddModfile(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModfileUploadDelegate.Broadcast((int32)response_code, (int32)mod_id);
}