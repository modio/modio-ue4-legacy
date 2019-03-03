#include "ModioSubsystem.h"
#include "ModioHWrapper.h"
#include "ModioSettings.h"
#include "ModioModule.h"

FModioSubsystem::FModioSubsystem() :
  Initialized( false )
{
}

FModioSubsystem::~FModioSubsystem()
{
  check(!Initialized);
}

void FModioSubsystem::Init()
{
  check(!Initialized);

  const UModioSettings *Settings = GetDefault<UModioSettings>();

  FString game_directory = FPaths::ConvertRelativePathToFull( FPaths::ProjectDir() );

  if( !Settings->RootDirectory.Len() )
  {
    UE_LOG( LogModio, Warning, TEXT( "No root directory defined for Modio, modio not initialized" ) );
    return;
  }

  if( Settings->GameId == 0 )
  {
    UE_LOG( LogModio, Warning, TEXT( "No GameId defined for Modio, modio not initialized" ) );
    return;
  }

  if( !Settings->ApiKey.Len() )
  {
    UE_LOG( LogModio, Warning, TEXT( "No ApiKey defined for Modio, modio not initialized" ) );
    return;
  }

  u32 environment;
  if( Settings->IsLiveEnvironment )
    environment = MODIO_ENVIRONMENT_LIVE;
  else
    environment = MODIO_ENVIRONMENT_TEST;

  game_directory += Settings->RootDirectory;

  u32 game_id = Settings->GameId;

  modioInit( environment, game_id, TCHAR_TO_UTF8( *Settings->ApiKey ), TCHAR_TO_UTF8( *game_directory ) );

  modioSetDownloadListener( &onModInstalled );
  modioSetUploadListener( &onAddModfile );

  Initialized = true;
}

void FModioSubsystem::Shutdown()
{
  check( Initialized );

  // I would assume that nullptr is valid to stop the callbacks comming in
  modioSetDownloadListener(nullptr);
  modioSetUploadListener(nullptr);

  Initialized = false;
}