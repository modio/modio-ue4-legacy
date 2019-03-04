#pragma once

#include "IModioModule.h"
#include "ModioSubsystem.h"
#include "ModioSettings.h"
#include "ModioCallbacks.h"

class FModioModule : public IModioModule
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
};