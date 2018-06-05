// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "modioModule.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FmodioModule"

modio::Instance *modio_instance;

void FmodioModule::StartupModule()
{
	modio_instance = new modio::Instance(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b");
}

void FmodioModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	delete modio_instance;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FmodioModule, modio)