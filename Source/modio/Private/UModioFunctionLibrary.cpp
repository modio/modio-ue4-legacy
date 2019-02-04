// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UModioFunctionLibrary.h"
#include "UModioComponent.h"
#include "ModioHWrapper.h"

extern modio::Instance *modio_instance;

UModioFunctionLibrary::UModioFunctionLibrary(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UModioFunctionLibrary::ModioProcess()
{
  modio_instance->process();
}

void UModioFunctionLibrary::ModioEmailRequest(FString email)
{
  modio_instance->emailRequest(std::string(TCHAR_TO_UTF8(*email)), [&](const modio::Response &response) {
    UModioComponent::OnEmailRequestDelegate.Broadcast((int32)response.code);
  });
}

void UModioFunctionLibrary::ModioEmailExchange(FString security_code)
{
  modio_instance->emailExchange(std::string(TCHAR_TO_UTF8(*security_code)), [&](const modio::Response &response) {
    modio_instance->getAuthenticatedUser([&](const modio::Response &response, const modio::User &user) {
      current_user_username = user.username;
    });

    UModioComponent::OnEmailExchangeDelegate.Broadcast((int32)response.code);
  });
}

void UModioFunctionLibrary::ModioLogout()
{
  modio_instance->logout();
}

void UModioFunctionLibrary::ModioIsLoggedIn(bool &is_logged_in)
{
  is_logged_in = modio_instance->isLoggedIn();
}

void UModioFunctionLibrary::ModioGetAuthenticatedUser(FString &username)
{
  username = UTF8_TO_TCHAR(current_user_username.c_str());
}

void UModioFunctionLibrary::ModioGetAllInstalledMod(TArray<FModioInstalledMod> &installed_mods)
{
  // TODO: use mod.io C++ wrapper instead of C
  u32 installed_mods_count = modioGetAllInstalledModsCount();
  ModioInstalledMod *modio_installed_mods = (ModioInstalledMod *)malloc(installed_mods_count * sizeof(*modio_installed_mods));
  modioGetAllInstalledMods(modio_installed_mods);

  for (u32 i = 0; i < installed_mods_count; i++)
  {
    FModioInstalledMod installed_mod;
    InitializeInstalledModC(installed_mod, modio_installed_mods[i]);
    installed_mods.Add(installed_mod);
  }

  free(modio_installed_mods);

  //const std::vector<modio::InstalledMod> modio_installed_mods = modio_instance->getAllInstalledMods();

  // use mod.io C++ wrapper instead of C
  /*
  const std::vector<modio::InstalledMod> modio_installed_mods = modio_instance->getAllInstalledMods();

  for (u32 i = 0; i < modio_installed_mods.size(); i++)
  {
    FModioInstalledMod installed_mod;
    InitializeInstalledModC(installed_mod, modio_installed_mods[i]);
    installed_mods.Add(installed_mod);
  }
  */
}

void UModioFunctionLibrary::ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &queued_mods)
{
  // TODO: use mod.io C++ wrapper instead of C
  u32 download_queue_count = modioGetModDownloadQueueCount();
  ModioQueuedModDownload *modio_queued_mods = (ModioQueuedModDownload *)malloc(download_queue_count * sizeof(*modio_queued_mods));
  modioGetModDownloadQueue(modio_queued_mods);

  for (u32 i = 0; i < download_queue_count; i++)
  {
    FModioQueuedModDownload queued_mod;
    InitializeQueuedModDownloadC(queued_mod, modio_queued_mods[i]);
    queued_mods.Add(queued_mod);
  }

  free(modio_queued_mods);
}

void UModioFunctionLibrary::ModioInstallDownloadedMods()
{
  modio_instance->installDownloadedMods();
}

void UModioFunctionLibrary::ModioGetAllMods(TEnumAsByte<EModioFilterType> filter_type, int32 limit, int32 offset)
{
  modio::FilterCreator filter_creator;
  filter_creator.setLimit((u32)limit);
  filter_creator.setOffset((u32)offset);

  modio_instance->getAllMods(filter_creator, [&](const modio::Response& response, const std::vector<modio::Mod> & mods) {
    UModioComponent::OnGetAllModsDelegate.Broadcast((int32)response.code, toTArrayMods(mods));
  });
}

void UModioFunctionLibrary::ModioAddMod(FModioModCreator mod_creator)
{
  modio::ModCreator modio_mod_creator;
  modio_mod_creator.setLogoPath(std::string(TCHAR_TO_UTF8(*mod_creator.LogoPath)));
  modio_mod_creator.setName(std::string(TCHAR_TO_UTF8(*mod_creator.Name)));
  modio_mod_creator.setSummary(std::string(TCHAR_TO_UTF8(*mod_creator.Summary)));

  modio_instance->addMod(modio_mod_creator, [&](const modio::Response& response, const modio::Mod& modio_mod)
  {
    FModioMod mod;
    InitializeMod(mod, modio_mod);
    UModioComponent::OnAddModDelegate.Broadcast((int32)response.code, mod);
  });
}

void UModioFunctionLibrary::ModioEditMod(int32 mod_id, FModioModEditor mod_editor)
{
  modio::ModEditor modio_mod_editor;
  modio_mod_editor.setName(std::string(TCHAR_TO_UTF8(*mod_editor.Name)));

  modio_instance->editMod(mod_id, modio_mod_editor, [&](const modio::Response& response, const modio::Mod& modio_mod)
  {
    FModioMod mod;
    InitializeMod(mod, modio_mod);
    UModioComponent::OnEditModDelegate.Broadcast((int32)response.code, mod);
  });
}

void UModioFunctionLibrary::ModioAddModfile(int32 mod_id, FModioModfileCreator modfile_creator)
{
  modio::ModfileCreator modio_modfile_creator;
  modio_modfile_creator.setPath(std::string(TCHAR_TO_UTF8(*modfile_creator.Path)));
  modio_instance->addModfile(mod_id, modio_modfile_creator);
}

void UModioFunctionLibrary::ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &upload_queue)
{
  // use mod.io C++ wrapper instead of C
  u32 upload_queue_count = modioGetModfileUploadQueueCount();
  ModioQueuedModfileUpload *modio_queued_mods = (ModioQueuedModfileUpload *)malloc(upload_queue_count * sizeof(*modio_queued_mods));
  modioGetModfileUploadQueue(modio_queued_mods);

  for (u32 i = 0; i < upload_queue_count; i++)
  {
    FModioQueuedModfileUpload queued_mod;
    InitializeQueuedModfileUploadC(queued_mod, modio_queued_mods[i]);
    upload_queue.Add(queued_mod);
  }

  free(modio_queued_mods);
}

void UModioFunctionLibrary::ModioGetUserSubscriptions()
{
  modio::FilterCreator filter_creator;
  modio_instance->getUserSubscriptions(filter_creator, [&](const modio::Response &response, const std::vector<modio::Mod> &mods) {
    UModioComponent::OnGetUserSubscriptionsDelegate.Broadcast((int32)response.code, toTArrayMods(mods));
  });
}