// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UModioComponent.h"

UModioComponent::FModioPlugin_OnEmailRequestDelegate UModioComponent::OnEmailRequestDelegate;
UModioComponent::FModioPlugin_OnEmailExchangeDelegate UModioComponent::OnEmailExchangeDelegate;
UModioComponent::FModioPlugin_OnModDownloadDelegate UModioComponent::OnModDownloadDelegate;
UModioComponent::FModioPlugin_OnModUploadDelegate UModioComponent::OnModUploadDelegate;
UModioComponent::FModioPlugin_OnGetAuthenticatedUserDelegate UModioComponent::OnGetAuthenticatedUserDelegate;
UModioComponent::FModioPlugin_OnGetAllModsDelegate UModioComponent::OnGetAllModsDelegate;
UModioComponent::FModioPlugin_OnGetUserSubscriptionsDelegate UModioComponent::OnGetUserSubscriptionsDelegate;
UModioComponent::FModioPlugin_OnAddModDelegate UModioComponent::OnAddModDelegate;
UModioComponent::FModioPlugin_OnEditModDelegate UModioComponent::OnEditModDelegate;

void UModioComponent::OnRegister()
{
	Super::OnRegister();
	OnEmailRequestDelegate.AddUObject(this, &UModioComponent::OnEmailRequestDelegate_Handler);
	OnEmailExchangeDelegate.AddUObject(this, &UModioComponent::OnEmailExchangeDelegate_Handler);
	OnModDownloadDelegate.AddUObject(this, &UModioComponent::OnModDownloadDelegate_Handler);
	OnModUploadDelegate.AddUObject(this, &UModioComponent::OnModUploadDelegate_Handler);
	OnGetAuthenticatedUserDelegate.AddUObject(this, &UModioComponent::OnGetAuthenticatedUserDelegate_Handler);
	OnGetAllModsDelegate.AddUObject(this, &UModioComponent::OnGetAllModsDelegate_Handler);
	OnGetUserSubscriptionsDelegate.AddUObject(this, &UModioComponent::OnGetAllModsDelegate_Handler);
	OnAddModDelegate.AddUObject(this, &UModioComponent::OnAddModDelegate_Handler);
	OnEditModDelegate.AddUObject(this, &UModioComponent::OnEditModDelegate_Handler);
}

void UModioComponent::OnUnregister()
{
	OnEmailRequestDelegate.RemoveAll(this);
	OnEmailExchangeDelegate.RemoveAll(this);
	OnModDownloadDelegate.RemoveAll(this);
	OnModUploadDelegate.RemoveAll(this);
	OnGetAuthenticatedUserDelegate.RemoveAll(this);
	OnGetAllModsDelegate.RemoveAll(this);
	OnGetUserSubscriptionsDelegate.RemoveAll(this);
	OnAddModDelegate.RemoveAll(this);
	OnEditModDelegate.RemoveAll(this);
	Super::OnUnregister();
}

void UModioComponent::OnEmailRequestDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnEmailRequestDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}


void UModioComponent::OnEmailExchangeDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnEmailExchangeDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnModDownloadDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModDownloadDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnModUploadDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModUploadDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FString username)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnGetAuthenticatedUserDynamicDelegate.Broadcast(response_code, username);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnGetAllModsDelegate_Handler(int32 response_code, TArray<FModioMod> mods)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnGetAllModsDynamicDelegate.Broadcast(response_code, mods);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnAddModDelegate_Handler(int32 response_code, FModioMod mod)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnAddModDynamicDelegate.Broadcast(response_code, mod);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnEditModDelegate_Handler(int32 response_code, FModioMod mod)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnEditModDynamicDelegate.Broadcast(response_code, mod);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnGetUserSubscriptionsDelegate_Handler(int32 response_code, TArray<FModioMod> mods)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnGetUserSubscriptionsDynamicDelegate.Broadcast(response_code, mods);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}