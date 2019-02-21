// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioCallbacks.h"

void onGetUserSubscriptions(void* object, ModioResponse response, ModioMod* mods, u32 mods_size)
{
  UModioComponent::OnGetUserSubscriptionsDelegate.Broadcast((int32)response.code, toTArrayMods(mods, mods_size));
}

void onGetAuthenticatedUser(void* object, ModioResponse response, ModioUser modio_user)
{
  FModioUser user;
  InitializeUser(user, modio_user);
  UModioComponent::OnGetAuthenticatedUserDelegate.Broadcast((int32)response.code, user);
}

void onModInstalled(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModDownloadDelegate.Broadcast((int32)response_code);
}

void onAddModfile(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModUploadDelegate.Broadcast((int32)response_code);
}