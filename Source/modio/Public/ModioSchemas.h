#pragma once

#include "Runtime/Core/Public/Modules/ModuleManager.h"

#include "ModioSchemas.generated.h"

UENUM(BlueprintType)
namespace ModioFilterEnum
{
enum Type
{
  SORT_BY_ID UMETA(DisplayName = "Sort by id"),
  SORT_BY_RATING UMETA(DisplayName = "Sort by rating"),
  SORT_BY_DATE_LIVE UMETA(DisplayName = "Sort by date live"),
  SORT_BY_DATE_UPDATED UMETA(DisplayName = "Sort by date updated")
};
}

USTRUCT(BlueprintType)
struct FModioMod
{
  GENERATED_BODY()

  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Summary;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Description;
};

USTRUCT(BlueprintType)
struct FModioInstalledMod
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod mod;
};

USTRUCT(BlueprintType)
struct FModioQueuedModDownload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  // TODO: change to int64 unsupported by ue4
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 CurrentProgress;
  // TODO: change to int64 unsupported by ue4
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 TotalSize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod mod;
};

extern void initializeMod(FModioMod &mod, modio::Mod modio_mod);
extern void initializeModC(FModioMod &mod, ModioMod modio_mod);
extern void initializeInstalledModC(FModioInstalledMod &installed_mod, ModioInstalledMod modio_installed_mod);
extern void initializeQueuedModDownloadC(FModioQueuedModDownload &queued_mod_download, ModioQueuedModDownload modio_queued_mod_download);