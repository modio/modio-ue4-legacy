// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UModioFunctionLibrary.h"
#include "UModioComponent.h"
#include "ModioHWrapper.h"

UModioFunctionLibrary::UModioFunctionLibrary(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UModioFunctionLibrary::ModioProcess()
{
  modioProcess();
}

void UModioFunctionLibrary::ModioLogout()
{
  modioLogout();
}

void UModioFunctionLibrary::ModioIsLoggedIn(bool &is_logged_in)
{
  is_logged_in = modioIsLoggedIn();
}

void UModioFunctionLibrary::ModioCurrentUser(FModioUser &user)
{
  InitializeUser(user, modioGetCurrentUser());
}

void UModioFunctionLibrary::ModioGetAllInstalledMod(TArray<FModioInstalledMod> &installed_mods)
{
  u32 installed_mods_count = modioGetAllInstalledModsCount();
  ModioInstalledMod *modio_installed_mods = (ModioInstalledMod *)malloc(installed_mods_count * sizeof(*modio_installed_mods));
  modioGetAllInstalledMods(modio_installed_mods);

  for (u32 i = 0; i < installed_mods_count; i++)
  {
    FModioInstalledMod installed_mod;
    InitializeInstalledMod(installed_mod, modio_installed_mods[i]);
    installed_mods.Add(installed_mod);
  }

  free(modio_installed_mods);
}

void UModioFunctionLibrary::ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &queued_mods)
{
  u32 download_queue_count = modioGetModDownloadQueueCount();
  ModioQueuedModDownload *modio_queued_mods = (ModioQueuedModDownload *)malloc(download_queue_count * sizeof(*modio_queued_mods));
  modioGetModDownloadQueue(modio_queued_mods);

  for (u32 i = 0; i < download_queue_count; i++)
  {
    FModioQueuedModDownload queued_mod;
    InitializeQueuedModDownload(queued_mod, modio_queued_mods[i]);
    queued_mods.Add(queued_mod);
  }

  free(modio_queued_mods);
}

void UModioFunctionLibrary::ModioInstallDownloadedMods()
{
  modioInstallDownloadedMods();
}

void UModioFunctionLibrary::ModioAddMod(FModioModCreator mod_creator)
{
  ModioModCreator modio_mod_creator;
  modioInitModCreator(&modio_mod_creator);
  modioSetModCreatorLogoPath(&modio_mod_creator, TCHAR_TO_UTF8(*mod_creator.LogoPath));
  modioSetModCreatorName(&modio_mod_creator, TCHAR_TO_UTF8(*mod_creator.Name));
  modioSetModCreatorSummary(&modio_mod_creator, TCHAR_TO_UTF8(*mod_creator.Summary));

  modioAddMod(NULL, modio_mod_creator, &onModAdded);
}

void UModioFunctionLibrary::ModioEditMod(int32 mod_id, FModioModEditor mod_editor)
{
  ModioModEditor modio_mod_editor;
  modioInitModEditor(&modio_mod_editor);
  modioSetModEditorName(&modio_mod_editor, TCHAR_TO_UTF8(*mod_editor.Name));

  modioEditMod(NULL, mod_id, modio_mod_editor, &onModEdited);
}

void UModioFunctionLibrary::ModioAddModfile(int32 mod_id, FModioModfileCreator modfile_creator)
{
  ModioModfileCreator modio_modfile_creator;
  modioInitModfileCreator(&modio_modfile_creator);
  modioSetModfileCreatorPath(&modio_modfile_creator, TCHAR_TO_UTF8(*modfile_creator.Path));
  modioAddModfile((u32)mod_id, modio_modfile_creator);
}

void UModioFunctionLibrary::ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &upload_queue)
{
  u32 upload_queue_count = modioGetModfileUploadQueueCount();
  ModioQueuedModfileUpload *modio_queued_mods = (ModioQueuedModfileUpload *)malloc(upload_queue_count * sizeof(*modio_queued_mods));
  modioGetModfileUploadQueue(modio_queued_mods);

  for (u32 i = 0; i < upload_queue_count; i++)
  {
    FModioQueuedModfileUpload queued_mod;
    InitializeQueuedModfileUpload(queued_mod, modio_queued_mods[i]);
    upload_queue.Add(queued_mod);
  }

  free(modio_queued_mods);
}

void UModioFunctionLibrary::ModioGetUserSubscriptions()
{
  ModioFilterCreator modio_filter_creator;
  modioInitFilter(&modio_filter_creator);
  modioGetUserSubscriptions(NULL, modio_filter_creator, &onGetUserSubscriptions);
}

void UModioFunctionLibrary::ModioGetAuthenticatedUser()
{
  modioGetAuthenticatedUser(NULL, &onGetAuthenticatedUser);
}