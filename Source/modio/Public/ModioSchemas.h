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
struct FModioLogo
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb320x180;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb640x360;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb1280x720;
};

USTRUCT(BlueprintType)
struct FModioAvatar
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb50x50;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb100x100;
};

USTRUCT(BlueprintType)
struct FModioUser
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateOnline;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Username;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString NameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Timezone;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Language;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString ProfileUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioAvatar Avatar;
};

USTRUCT(BlueprintType)
struct FModioFilehash
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Md5;
};

USTRUCT(BlueprintType)
struct FModioDownload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateExpires;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString BinaryUrl;
};

USTRUCT(BlueprintType)
struct FModioModfile
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 VirusStats;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 VirusPositive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateScanned;
  // TODO use int 64 instead of 32
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Filesize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Version;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString VirustotalHash;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Changelog;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString MetadataBlob;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioFilehash Filehash;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioDownload Download;
};

USTRUCT(BlueprintType)
struct FModioMod
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 GameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Status;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Visible;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 MaturityOption;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateUpdated;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateLive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString HomepageUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString NameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Summary;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Description;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString DescriptionPlainText;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString MetadataBlob;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString ProfileUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioLogo Logo;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioUser SubmittedBy;
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

USTRUCT(BlueprintType)
struct FModioQueuedModfileUpload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 State;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 CurrentProgress;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 TotalSize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
};

USTRUCT(BlueprintType)
struct FModioModCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString LogoPath;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Summary;
};

USTRUCT(BlueprintType)
struct FModioModfileCreator
{
  GENERATED_BODY()
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
};

USTRUCT(BlueprintType)
struct FModioModEditor
{
  GENERATED_BODY()
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
};

extern void initializeLogo(FModioLogo &Logo, modio::Logo modio_logo);
extern void initializeLogoC(FModioLogo &Logo, ModioLogo modio_logo);
extern void initializeAvatar(FModioAvatar &Avatar, modio::Avatar modio_avatar);
extern void initializeAvatarC(FModioAvatar &Avatar, ModioAvatar modio_avatar);
extern void initializeUser(FModioUser &User, modio::User modio_user);
extern void initializeUserC(FModioUser &User, ModioUser modio_user);
extern void initializeFilehash(FModioFilehash &filehash, modio::Filehash modio_filehash);
extern void initializeFileHashC(FModioFilehash &filehash, ModioFilehash modio_filehash);
extern void initializeDownload(FModioDownload &download, modio::Download modio_download);
extern void initializeDownloadC(FModioDownload &download, ModioDownload modio_download);
extern void initializeModfile(FModioModfile &modfile, modio::Modfile modio_modfile);
extern void initializeModfileC(FModioModfile &modfile, ModioModfile modio_modfile);
extern void initializeMod(FModioMod &mod, modio::Mod modio_mod);
extern void initializeModC(FModioMod &mod, ModioMod modio_mod);
extern void initializeInstalledModC(FModioInstalledMod &installed_mod, ModioInstalledMod modio_installed_mod);
extern void initializeQueuedModDownloadC(FModioQueuedModDownload &queued_mod_download, ModioQueuedModDownload modio_queued_mod_download);
extern void initializeQueuedModfileUploadC(FModioQueuedModfileUpload &queued_modfile_upload, ModioQueuedModfileUpload modio_queued_modfile_upload);