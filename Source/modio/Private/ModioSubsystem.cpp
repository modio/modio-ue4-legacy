#include "ModioSubsystem.h"
#include "ModioHWrapper.h"
#include "ModioSettings.h"
#include "ModioModule.h"

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

void FModioSubsystem::Init( const FString& RootDirectory, uint32 GameId, const FString& ApiKey, bool bIsLiveEnvironment )
{
  check(!bInitialized);

  u32 Environment = bIsLiveEnvironment ? MODIO_ENVIRONMENT_LIVE : MODIO_ENVIRONMENT_TEST;
  
  modioInit( Environment, (u32)GameId, TCHAR_TO_UTF8(*ApiKey), TCHAR_TO_UTF8(*RootDirectory) );

  modioSetDownloadListener(&onModInstalled);
  modioSetUploadListener(&onAddModfile);

  bInitialized = true;
}

void FModioSubsystem::Shutdown()
{
  check(bInitialized);

  // I would assume that nullptr is valid to stop the callbacks comming in
  modioSetDownloadListener(nullptr);
  modioSetUploadListener(nullptr);

  bInitialized = false;
}