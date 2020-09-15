// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Modules/ModuleManager.h"

class FInt64EditorModule : public IModuleInterface
{
public:
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;
  virtual bool SupportsDynamicReloading() override;
};