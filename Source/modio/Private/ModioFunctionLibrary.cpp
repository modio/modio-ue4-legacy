// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioFunctionLibrary.h"
#include "ModioHWrapper.h"
#include "ModioUE4Utility.h"
#include "Engine/Engine.h"

UModioFunctionLibrary::UModioFunctionLibrary(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UModioFunctionLibrary::ModioProcess(UObject *WorldContextObject)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->Process();
  }
}

void UModioFunctionLibrary::ModioLogout(UObject *WorldContextObject)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->Logout();
  }
}

void UModioFunctionLibrary::ModioIsLoggedIn(UObject *WorldContextObject, bool &IsLoggedIn)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    IsLoggedIn = Modio->IsLoggedIn();
  }
}

void UModioFunctionLibrary::ModioCurrentUser(UObject *WorldContextObject, FModioUser &User)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    User = Modio->CurrentUser();
  }
}

void UModioFunctionLibrary::ModioGetInstalledMod(UObject *WorldContextObject, int32 ModId, FString &Path, FModioMod &Mod)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    FModioInstalledMod InstalledMod = Modio->GetInstalledMod(ModId);
    Path = InstalledMod.Path;
    Mod = InstalledMod.Mod;
  }
}

void UModioFunctionLibrary::ModioGetAllInstalledMods(UObject *WorldContextObject, TArray<FModioInstalledMod> &InstalledMods)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    InstalledMods = Modio->GetAllInstalledMods();
  }
}

void UModioFunctionLibrary::ModioGetAllDownloadedMods(UObject *WorldContextObject, TArray<int32> &DownloadedMods)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    DownloadedMods = Modio->GetAllDownloadedMods();
  }
}

void UModioFunctionLibrary::ModioGetModDownloadQueue(UObject *WorldContextObject, TArray<FModioQueuedModDownload> &QueuedMods)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    QueuedMods = Modio->GetModDownloadQueue();
  }
}

void UModioFunctionLibrary::ModioInstallDownloadedMods(UObject *WorldContextObject)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->InstallDownloadedMods();
  }
}

void UModioFunctionLibrary::ModioAddModfile(UObject *WorldContextObject, int32 ModId, FModioModfileCreator ModfileCreator)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->AddModfile(ModId, ModfileCreator);
  }
}

void UModioFunctionLibrary::ModioGetModfileUploadQueue(UObject *WorldContextObject, TArray<FModioQueuedModfileUpload> &UploadQueue)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    UploadQueue = Modio->GetModfileUploadQueue();
  }
}

void UModioFunctionLibrary::ModioGetModState(UObject *WorldContextObject, int32 ModId, uint8 &ModState)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    ModState = Modio->GetModState(ModId);
  }else
  {
    ModState = EModioModState::NOT_DEFINED;
  }
}

void UModioFunctionLibrary::ModioGetUserModRating(UObject *WorldContextObject, int32 ModId, uint8 &ModRating)
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    ModRating = Modio->GetUserModRating(ModId);
  }else
  {
    ModRating = EModioRatingType::RATING_NOT_DEFINED;
  }
}