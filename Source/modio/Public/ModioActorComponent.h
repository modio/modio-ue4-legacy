// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Components/ActorComponent.h"
#include "ModioSubsystem.h"
#include "ModioActorComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), DisplayName = "mod.io Actor Component")
class MODIO_API UModioActorComponent : public UActorComponent
{
  GENERATED_UCLASS_BODY()

  FModioSubsystemPtr Modio;

  void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};