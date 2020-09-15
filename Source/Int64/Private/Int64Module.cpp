// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Int64Module.h"

void FInt64Module::StartupModule()
{
}

void FInt64Module::ShutdownModule()
{
}

bool FInt64Module::SupportsDynamicReloading()
{
	return true;
}

IMPLEMENT_MODULE( FInt64Module, Int64 )