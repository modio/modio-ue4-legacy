#pragma once

#include "Templates/SharedPointer.h"

/**
 * Baseclass for async requests. Helps keep the implementation cleaner when doing
 * different async requests
 */
struct FModioAsyncRequest :
  TSharedFromThis<FModioAsyncRequest>
{
public:
  FModioAsyncRequest() = delete;
  FModioAsyncRequest(const FModioAsyncRequest& Other) = delete;
  
  FModioAsyncRequest( struct FModioSubsystem *Modio );
protected:
  /** Call this in your subclass when you are done with your object */
  void Done();

  struct FModioSubsystem *ModioSubsystem;
};