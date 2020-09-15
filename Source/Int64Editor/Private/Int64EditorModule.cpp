// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Int64EditorModule.h"
#include "Modules/ModuleManager.h"
#include "Int64DetailCustomization.h"
#include "PropertyEditorModule.h"
#include "Int64.h"

void FInt64EditorModule::StartupModule()
{
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>( "PropertyEditor" );
		PropertyModule.RegisterCustomPropertyTypeLayout( FInt64::StaticStruct()->GetFName(), FOnGetPropertyTypeCustomizationInstance::CreateStatic( &FInt64DetailCustomization::MakeInstance ) );
	}
}

void FInt64EditorModule::ShutdownModule()
{
}

bool FInt64EditorModule::SupportsDynamicReloading()
{
	return true;
}

IMPLEMENT_MODULE( FInt64EditorModule, Int64Editor )