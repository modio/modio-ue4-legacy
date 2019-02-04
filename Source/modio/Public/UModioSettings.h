// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "UModioSettings.generated.h"

UCLASS(config = Game, defaultconfig)
class UModioSettings : public UObject
{
  GENERATED_BODY()

public:
  UModioSettings(const FObjectInitializer &ObjectInitializer);

  UPROPERTY(EditAnywhere, config, Category = Custom)
  bool IsLiveEnvironment;

  UPROPERTY(EditAnywhere, config, Category = Custom, meta = (UIMin = 1, ClampMin = 1))
  int32 GameId;

  UPROPERTY(EditAnywhere, config, Category = Custom)
  FString ApiKey;

  UPROPERTY(EditAnywhere, config, Category = Custom)
  FString RootDirectory;
};