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

	/* Multicast Delegates */
	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailRequestDelegate,
		int32
	);
	static FModioPlugin_OnEmailRequestDelegate OnEmailRequestDelegate;

	DECLARE_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailExchangeDelegate,
		int32
	);
	static FModioPlugin_OnEmailExchangeDelegate OnEmailExchangeDelegate;

	/* Dynamic Multicast Delegates */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailRequestDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailRequest"))
	FModioPlugin_OnEmailRequestDynamicDelegate OnEmailRequestDynamicDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FModioPlugin_OnEmailExchangeDynamicDelegate,
		int32,
		response_code
	);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "mod.io OnEmailExchange"))
	FModioPlugin_OnEmailExchangeDynamicDelegate OnEmailExchangeDynamicDelegate;
private:
	void OnEmailRequestDelegate_Handler(int32 response_code);
	void OnEmailExchangeDelegate_Handler(int32 response_code);
};