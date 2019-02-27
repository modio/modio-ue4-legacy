// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "UModioComponent.h"

UModioComponent::FModioPlugin_OnModDownloadDelegate UModioComponent::OnModDownloadDelegate;
UModioComponent::FModioPlugin_OnModUploadDelegate UModioComponent::OnModUploadDelegate;

void UModioComponent::OnRegister()
{
  Super::OnRegister();
  OnModDownloadDelegate.AddUObject(this, &UModioComponent::OnModDownloadDelegate_Handler);
  OnModUploadDelegate.AddUObject(this, &UModioComponent::OnModUploadDelegate_Handler);
}

void UModioComponent::OnUnregister()
{
	OnModDownloadDelegate.RemoveAll(this);
	OnModUploadDelegate.RemoveAll(this);
	Super::OnUnregister();
}

void UModioComponent::OnModDownloadDelegate_Handler(int32 response_code, int32 mod_id)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModDownloadDynamicDelegate.Broadcast(response_code, mod_id);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnModUploadDelegate_Handler(int32 response_code, int32 mod_id)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModUploadDynamicDelegate.Broadcast(response_code, mod_id);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}