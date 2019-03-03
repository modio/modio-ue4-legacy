#pragma once

#include "CoreMinimal.h"

/**
 * Interface for the modio c++ UE4 API. Please note that this class shouldn't
 * hold any references to any UObjects derived classes, as it is right now, as it's
 * not exposed to the GC. Reference objects with WeakObjectPointer if you want to
 * hold references to Object/Actors. And keep other pointers with Shared/Unique ptrs
 */
struct MODIO_API FModioSubsystem : 
  public TSharedFromThis<FModioSubsystem, ESPMode::ThreadSafe>
{
  FModioSubsystem();

  virtual ~FModioSubsystem();

  /** Can be called multiple times during a session, as long as it's properly paired with it's shutdown */
  void Init();

  /** Properly shutdowns modio */
  void Shutdown();
private:
  /** Are we initialized */
  uint8 Initialized:1;
};

typedef TSharedPtr<FModioSubsystem, ESPMode::ThreadSafe> FModioSubsystemPtr;