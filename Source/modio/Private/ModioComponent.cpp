// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioComponent.h"

UModioComponent::FModioPlugin_OnModDownloadDelegate UModioComponent::OnModDownloadDelegate;
UModioComponent::FModioPlugin_OnModfileUploadDelegate UModioComponent::OnModfileUploadDelegate;

void UModioComponent::OnRegister()
{
  Super::OnRegister();
  OnModDownloadDelegate.AddUObject(this, &UModioComponent::OnModDownloadDelegate_Handler);
  OnModfileUploadDelegate.AddUObject(this, &UModioComponent::OnModfileUploadDelegate_Handler);
}

void UModioComponent::OnUnregister()
{
	OnModDownloadDelegate.RemoveAll(this);
	OnModfileUploadDelegate.RemoveAll(this);
	Super::OnUnregister();
}

void UModioComponent::OnModDownloadDelegate_Handler(int32 response_code, int32 mod_id)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModDownloadDynamicDelegate.Broadcast(response_code, mod_id);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioComponent::OnModfileUploadDelegate_Handler(int32 response_code, int32 mod_id)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModfileUploadDynamicDelegate.Broadcast(response_code, mod_id);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}