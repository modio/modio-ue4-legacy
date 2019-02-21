// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UModioComponent.h"

UModioComponent::FModioPlugin_OnModDownloadDelegate UModioComponent::OnModDownloadDelegate;
UModioComponent::FModioPlugin_OnModUploadDelegate UModioComponent::OnModUploadDelegate;
UModioComponent::FModioPlugin_OnGetUserSubscriptionsDelegate UModioComponent::OnGetUserSubscriptionsDelegate;
UModioComponent::FModioPlugin_OnGetAuthenticatedUserDelegate UModioComponent::OnGetAuthenticatedUserDelegate;

void UModioComponent::OnRegister()
{
  Super::OnRegister();
  OnModDownloadDelegate.AddUObject(this, &UModioComponent::OnModDownloadDelegate_Handler);
  OnModUploadDelegate.AddUObject(this, &UModioComponent::OnModUploadDelegate_Handler);
  OnGetUserSubscriptionsDelegate.AddUObject(this, &UModioComponent::OnGetUserSubscriptionsDelegate_Handler);
  OnGetAuthenticatedUserDelegate.AddUObject(this, &UModioComponent::OnGetAuthenticatedUserDelegate_Handler);
}

void UModioComponent::OnUnregister()
{
	OnModDownloadDelegate.RemoveAll(this);
	OnModUploadDelegate.RemoveAll(this);
	OnGetUserSubscriptionsDelegate.RemoveAll(this);
	OnGetAuthenticatedUserDelegate.RemoveAll(this);
	Super::OnUnregister();
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

void UModioComponent::OnGetUserSubscriptionsDelegate_Handler(int32 response_code, TArray<FModioMod> mods)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnGetUserSubscriptionsDynamicDelegate.Broadcast(response_code, mods);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FModioUser user)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnGetAuthenticatedUserDynamicDelegate.Broadcast(response_code, user);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}