// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioCallbacks.h"

void onModInstalled(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModDownloadDelegate.Broadcast((int32)response_code);
}

void onAddModfile(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModUploadDelegate.Broadcast((int32)response_code);
}