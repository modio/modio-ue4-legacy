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
	delete modio_instance;
}

UModioBPFunctionLibrary::UModioBPFunctionLibrary(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UModioBPFunctionLibrary::modioProcess()
{
	modio_instance->process();
}

void UModioBPFunctionLibrary::modioEmailRequest(FString email)
{
	modio_instance->emailRequest(std::string(TCHAR_TO_UTF8(*email)), [&](const modio::Response &response) {
		UModioPluginComponent::OnEmailRequestDelegate.Broadcast((int32)response.code);
	});
}

void UModioBPFunctionLibrary::modioEmailExchange(FString security_code)
{
	modio_instance->emailExchange(std::string(TCHAR_TO_UTF8(*security_code)), [&](const modio::Response &response) {
		UModioPluginComponent::OnEmailExchangeDelegate.Broadcast((int32)response.code);
	});
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FmodioModule, modio)