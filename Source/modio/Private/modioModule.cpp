// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "modioModule.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FmodioModule"

modio::Instance *modio_instance;

void FmodioModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("modio")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;

#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/modioSDK/bin/visualc++/x64/modio.dll"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/modioSDK/lib/osx/libmodio.dylib"));
#endif // PLATFORM_WINDOWS

	modio_handle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
	
	FText TestHUDText = FText::FromString(LibraryPath);
	FMessageDialog::Open(EAppMsgType::Ok, TestHUDText);

	if (modio_handle)
	{
		// Call the test function in the third party library that opens a message box
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "Mod.io plugin loaded"));
		//modio::Instance x(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b");
		//modioIsLoggedIn();
		modio_instance = new modio::Instance(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b");
		/*
		if(modio_instance->isLoggedIn())
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "Logged in"));
		else
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "Not logged in"));
		*/
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}
}

void FmodioModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	/*
	FPlatformProcess::FreeDllHandle(modio_handle);
	modio_handle = nullptr;
	delete modio_instance;
	*/
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FmodioModule, modio)