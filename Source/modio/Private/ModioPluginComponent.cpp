#include "ModioPluginComponent.h"
#include "Engine/Engine.h"

UModioPluginComponent::FModioPlugin_OnEmailRequestDelegate UModioPluginComponent::OnEmailRequestDelegate;
UModioPluginComponent::FModioPlugin_OnEmailExchangeDelegate UModioPluginComponent::OnEmailExchangeDelegate;
UModioPluginComponent::FModioPlugin_OnModDownloadDelegate UModioPluginComponent::OnModDownloadDelegate;
UModioPluginComponent::FModioPlugin_OnGetAuthenticatedUserDelegate UModioPluginComponent::OnGetAuthenticatedUserDelegate;

void UModioPluginComponent::OnRegister()
{
	Super::OnRegister();
	OnEmailRequestDelegate.AddUObject(this, &UModioPluginComponent::OnEmailRequestDelegate_Handler);
	OnEmailExchangeDelegate.AddUObject(this, &UModioPluginComponent::OnEmailExchangeDelegate_Handler);
	OnModDownloadDelegate.AddUObject(this, &UModioPluginComponent::OnModDownloadDelegate_Handler);
	OnGetAuthenticatedUserDelegate.AddUObject(this, &UModioPluginComponent::OnGetAuthenticatedUserDelegate_Handler);
}

void UModioPluginComponent::OnUnregister()
{
	OnEmailRequestDelegate.RemoveAll(this);
	OnEmailExchangeDelegate.RemoveAll(this);
	OnModDownloadDelegate.RemoveAll(this);
	OnGetAuthenticatedUserDelegate.RemoveAll(this);
	Super::OnUnregister();
}

void UModioPluginComponent::OnEmailRequestDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnEmailRequestDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioPluginComponent::OnEmailExchangeDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnEmailExchangeDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioPluginComponent::OnModDownloadDelegate_Handler(int32 response_code)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnModDownloadDynamicDelegate.Broadcast(response_code);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}

void UModioPluginComponent::OnGetAuthenticatedUserDelegate_Handler(int32 response_code, FString username)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
	{
		OnGetAuthenticatedUserDynamicDelegate.Broadcast(response_code, username);
	}, TStatId(), NULL, ENamedThreads::GameThread);
}