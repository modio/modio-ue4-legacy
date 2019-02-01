// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "modio.h"
#include "ModioUE4Utility.h"
#include "UModioComponent.h"
#include "UModioSettings.h"

extern modio::Instance *modio_instance;
extern std::string current_user_username;

class FModioModule : public IModuleInterface
{
public:
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;
  virtual bool SupportsDynamicReloading() override;

private:
  bool HandleSettingsSaved();
  void RegisterSettings();
  void UnregisterSettings();
};