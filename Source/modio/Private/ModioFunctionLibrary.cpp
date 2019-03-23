// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioFunctionLibrary.h"
#include "ModioComponent.h"
#include "ModioHWrapper.h"
#include "ModioUE4Utility.h"

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

void UModioFunctionLibrary::ModioIsLoggedIn(bool &IsLoggedIn)
{
  IsLoggedIn = modioIsLoggedIn();
}

void UModioFunctionLibrary::ModioCurrentUser(FModioUser &User)
{
  InitializeUser(User, modioGetCurrentUser());
}

void UModioFunctionLibrary::ModioGetAllInstalledMod(TArray<FModioInstalledMod> &InstalledMods)
{
  u32 installed_mods_count = modioGetAllInstalledModsCount();
  ModioInstalledMod *modio_installed_mods = (ModioInstalledMod *)malloc(installed_mods_count * sizeof(*modio_installed_mods));
  modioGetAllInstalledMods(modio_installed_mods);

  for (u32 i = 0; i < installed_mods_count; i++)
  {
    FModioInstalledMod installed_mod;
    InitializeInstalledMod(installed_mod, modio_installed_mods[i]);
    InstalledMods.Add(installed_mod);
  }

  free(modio_installed_mods);
}

void UModioFunctionLibrary::ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &QueuedMods)
{
  u32 download_queue_count = modioGetModDownloadQueueCount();
  ModioQueuedModDownload *modio_queued_mods = (ModioQueuedModDownload *)malloc(download_queue_count * sizeof(*modio_queued_mods));
  modioGetModDownloadQueue(modio_queued_mods);

  for (u32 i = 0; i < download_queue_count; i++)
  {
    FModioQueuedModDownload queued_mod;
    InitializeQueuedModDownload(queued_mod, modio_queued_mods[i]);
    QueuedMods.Add(queued_mod);
  }

  free(modio_queued_mods);
}

void UModioFunctionLibrary::ModioInstallDownloadedMods()
{
  modioInstallDownloadedMods();
}

void UModioFunctionLibrary::ModioAddModfile(int32 ModId, FModioModfileCreator ModfileCreator)
{
  ModioModfileCreator modio_modfile_creator;
  modioInitModfileCreator(&modio_modfile_creator);
  SetupModioModfileCreator(ModfileCreator, modio_modfile_creator);
  modioAddModfile((u32)ModId, modio_modfile_creator);
  modioFreeModfileCreator(&modio_modfile_creator);
}

void UModioFunctionLibrary::ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &UploadQueue)
{
  u32 upload_queue_count = modioGetModfileUploadQueueCount();
  ModioQueuedModfileUpload *modio_queued_mods = (ModioQueuedModfileUpload *)malloc(upload_queue_count * sizeof(*modio_queued_mods));
  modioGetModfileUploadQueue(modio_queued_mods);

  for (u32 i = 0; i < upload_queue_count; i++)
  {
    FModioQueuedModfileUpload queued_mod;
    InitializeQueuedModfileUpload(queued_mod, modio_queued_mods[i]);
    UploadQueue.Add(queued_mod);
  }

  free(modio_queued_mods);
}