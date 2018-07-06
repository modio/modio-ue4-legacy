#include "ModioPluginComponent.h"
#include "Engine/Engine.h"

UModioPluginComponent::FModioPlugin_OnEmailRequestDelegate UModioPluginComponent::OnEmailRequestDelegate;
UModioPluginComponent::FModioPlugin_OnEmailExchangeDelegate UModioPluginComponent::OnEmailExchangeDelegate;

void UModioPluginComponent::OnRegister()
{
	Super::OnRegister();
	OnEmailRequestDelegate.AddUObject(this, &UModioPluginComponent::OnEmailRequestDelegate_Handler);
	OnEmailExchangeDelegate.AddUObject(this, &UModioPluginComponent::OnEmailExchangeDelegate_Handler);
}

void UModioPluginComponent::OnUnregister()
{
	OnEmailRequestDelegate.RemoveAll(this);
	OnEmailExchangeDelegate.RemoveAll(this);
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