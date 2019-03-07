#include "ModioAsyncRequest.h"
#include "ModioSubsystem.h"

FModioAsyncRequest::FModioAsyncRequest( FModioSubsystem *Modio ) :
  ModioSubsystem( Modio )
{
  checkf(Modio, TEXT("Trying to pass a bad ModioSubsystem to a async request") );
}

void FModioAsyncRequest::Done()
{
  ModioSubsystem->AsyncRequestDone( this );
}