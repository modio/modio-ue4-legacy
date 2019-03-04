#pragma once

#include "CoreMinimal.h"
#include "ModioPackage.h"

typedef TSharedPtr<struct FModioSubsystem, ESPMode::ThreadSafe> FModioSubsystemPtr;

/**
 * Interface for the modio c++ UE4 API. Please note that this class shouldn't
 * hold any references to any UObjects derived classes, as it is right now, as it's
 * not exposed to the GC. Reference objects with WeakObjectPointer if you want to
 * hold references to Object/Actors. And keep other pointers with Shared/Unique ptrs
 */
struct MODIO_API FModioSubsystem : 
  public TSharedFromThis<FModioSubsystem, ESPMode::ThreadSafe>
{
public:
  virtual ~FModioSubsystem();
protected:
  friend class FModioModule;
  static FModioSubsystemPtr Create( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironment );
PACKAGE_SCOPE:
  /** Should only be create from our create function */
  FModioSubsystem();

  /** Can be called multiple times during a session, as long as it's properly paired with it's shutdown */
  void Init( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironent );

  /** Properly shutdowns modio */
  void Shutdown();
private:
  /** Are we initialized */
  uint8 bInitialized:1;
};

typedef TSharedPtr<FModioSubsystem, ESPMode::ThreadSafe> FModioSubsystemPtr;