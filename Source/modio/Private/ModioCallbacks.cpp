// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioCallbacks.h"
#include "ModioSubsystem.h"

void onModDownload(u32 response_code, u32 mod_id)
{
  FModioSubsystem::ModioOnModDownloadDelegate.ExecuteIfBound( (int32)response_code, (int32)mod_id );
}

void onModUpload(u32 response_code, u32 mod_id)
{
  FModioSubsystem::ModioOnModUploadDelegate.ExecuteIfBound( (int32)response_code, (int32)mod_id );
}