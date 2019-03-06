#include "ModioSubsystem.h"
#include "ModioHWrapper.h"
#include "ModioPublic.h"
#include "ModioSettings.h"
#include "ModioModule.h"
#include "AsyncRequest/ModioAsyncRequest.h"
#include "FModioResponse.h"
#include "ModioCallbacks.h"

class FModioAsyncRequest_EmailExchange : public FModioAsyncRequest
{
public:
  FModioAsyncRequest_EmailExchange( FModioSubsystem *Modio, FEmailExchangeDelegate Delegate ) :
    FModioAsyncRequest( Modio ),
    ResponseDelegate( Delegate )
  {
  }
  static void Response( void *Object, ModioResponse ModioResponse )
  {
    FModioResponse Response;
    InitializeResponse( Response, ModioResponse );

    FModioAsyncRequest_EmailExchange* ThisPointer = (FModioAsyncRequest_EmailExchange*)Object;
    ThisPointer->ResponseDelegate.ExecuteIfBound( Response );

    ThisPointer->Done();
  }

private:
  FEmailExchangeDelegate ResponseDelegate;
};

FModioSubsystem::FModioSubsystem() :
  bInitialized(false)
{
}

FModioSubsystem::~FModioSubsystem()
{
  check(!bInitialized);
}

FModioSubsystemPtr FModioSubsystem::Create( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironent )
{
  if( !RootDirectory.Len() )
  {
    UE_LOG( LogModio, Warning, TEXT( "No root directory defined for Modio, modio not initialized" ) );
    return nullptr;
  }

  if( GameId == 0 )
  {
    UE_LOG( LogModio, Warning, TEXT( "No GameId defined for Modio, modio not initialized" ) );
    return nullptr;
  }

  if( !ApiKey.Len() )
  {
    UE_LOG( LogModio, Warning, TEXT( "No ApiKey defined for Modio, modio not initialized" ) );
    return nullptr;
  }

  FString GameDirectory = FPaths::ConvertRelativePathToFull( FPaths::ProjectDir() );
  GameDirectory += RootDirectory;

  FModioSubsystemPtr Modio = MakeShared<FModioSubsystem, ESPMode::ThreadSafe>();
  Modio->Init( GameDirectory, GameId, ApiKey, bIsLiveEnvironent );

  return Modio;
}

void FModioSubsystem::EmailExchange( const FString &SecurityCode, FEmailExchangeDelegate ExchangeDelegate )
{
  FModioAsyncRequest_EmailExchange *Request = new FModioAsyncRequest_EmailExchange( this, ExchangeDelegate );
  modioEmailRequest( Request, TCHAR_TO_UTF8(*SecurityCode), FModioAsyncRequest_EmailExchange::Response );
  QueueAsyncTask( Request );
}

void FModioSubsystem::Init( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironment )
{
  check(!bInitialized);

  u32 Environment = bIsLiveEnvironment ? MODIO_ENVIRONMENT_LIVE : MODIO_ENVIRONMENT_TEST;
  
  modioInit( Environment, (u32)GameId, TCHAR_TO_UTF8(*ApiKey), TCHAR_TO_UTF8(*RootDirectory) );

  modioSetDownloadListener(&onModInstalled);
  modioSetUploadListener(&onAddModfile);

  bInitialized = true;
}

void FModioSubsystem::QueueAsyncTask( struct FModioAsyncRequest* Request )
{
  checkf(Request, TEXT("Trying to queue up a invalid async request"));
  TSharedPtr<FModioAsyncRequest> SharedRequest = MakeShareable(Request);
  checkf(!AsyncRequests.Contains(SharedRequest), TEXT("Trying queue a async request twice"));

  AsyncRequests.Add(SharedRequest);
}

void FModioSubsystem::AsyncRequestDone( struct FModioAsyncRequest *Request )
{
  checkf(Request, TEXT("Passing in a bad request to AsyncRequestDone"));
  checkf(AsyncRequests.Contains(Request->AsShared()), TEXT("Async Request marking itself as done multiple times"));

  AsyncRequests.RemoveSwap(Request->AsShared());
}

void FModioSubsystem::Shutdown()
{
  check(bInitialized);

  // I would assume that nullptr is valid to stop the callbacks comming in
  modioSetDownloadListener(nullptr);
  modioSetUploadListener(nullptr);

  bInitialized = false;
}


namespace ModioCallback
{
}