// Copyright 2015 Moritz Wundke. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioGameSettings.generated.h"

/**
 * Setting object used to hold both config settings and editable ones in one place
 * To ensure the settings are saved to the specified config file make sure to add
 * props using the globalconfig or config meta.
 */
UCLASS(config = Game, defaultconfig)
class UModioGameSettings : public UObject
{
	GENERATED_BODY()

public:
	UModioGameSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, config, Category = Custom)
	bool IsLiveEnvironment;

	UPROPERTY(EditAnywhere, config, Category = Custom, meta = (UIMin = 1, ClampMin = 1))
	int32 GameId;

	UPROPERTY(EditAnywhere, config, Category = Custom)
	FString ApiKey;

	UPROPERTY(EditAnywhere, config, Category = Custom)
	FString RootDirectory;
};