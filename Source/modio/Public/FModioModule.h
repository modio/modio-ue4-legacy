// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Modules/ModuleManager.h"
#include "ModioHWrapper.h"
#include "ModioUE4Utility.h"
#include "UModioComponent.h"
#include "UModioSettings.h"

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