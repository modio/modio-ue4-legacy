// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "UModioSettings.h"
#include "ModioCallbacks.h"
#include "Modules/ModuleManager.h"

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