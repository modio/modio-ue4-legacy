#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "ModioPluginComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), DisplayName = "ModioPlugin")
class UModioPluginComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void OnRegister() override;
	void OnUnregister() override;

	/* onEmailRequest */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailRequestDelegate,
		int32
	);
	static FModioPlugin_OnEmailRequestDelegate OnEmailRequestDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailRequestDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailRequest"))
	FModioPlugin_OnEmailRequestDynamicDelegate OnEmailRequestDynamicDelegate;

	/* onEmailExchange */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailExchangeDelegate,
		int32
	);
	static FModioPlugin_OnEmailExchangeDelegate OnEmailExchangeDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailExchangeDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailExchange"))
	FModioPlugin_OnEmailExchangeDynamicDelegate OnEmailExchangeDynamicDelegate;
	
	/* onModDownload */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnModDownloadDelegate,
		int32
	);
	static FModioPlugin_OnModDownloadDelegate OnModDownloadDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnModDownloadDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnModDownload"))
	FModioPlugin_OnModDownloadDynamicDelegate OnModDownloadDynamicDelegate;

private:
	void OnEmailRequestDelegate_Handler(int32 response_code);
	void OnEmailExchangeDelegate_Handler(int32 response_code);
	void OnModDownloadDelegate_Handler(int32 response_code);
};