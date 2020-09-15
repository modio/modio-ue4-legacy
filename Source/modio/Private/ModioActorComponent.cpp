// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "ModioActorComponent.h"

UModioActorComponent::UModioActorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;

    this->Modio = FModioSubsystem::Get(GetWorld());
}

void UModioActorComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Modio->Process();
}