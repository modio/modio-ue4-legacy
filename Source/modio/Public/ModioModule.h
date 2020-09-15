// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Modules/ModuleManager.h"

class FModioModule : public IModuleInterface
{
public:
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;
  virtual bool SupportsDynamicReloading() override;

  FModioSubsystemPtr GetModioImp(UWorld *World) const;

private:
  bool HandleSettingsSaved();
  void RegisterSettings();
  void UnregisterSettings();

  FModioSubsystemPtr ModioImp;
#if PLATFORM_WINDOWS
  void* DLLHandle;
 #endif
};