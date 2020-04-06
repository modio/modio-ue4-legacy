// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSettings.generated.h"

/**
 * In editor, where will the modio calls be processed.
 */
UENUM()
enum class ERunInEditorOn : uint8
{
  FirstServer     UMETA( DisplayName = "Server", ToolTip="Server only (and Editor)"),
  FirstClient     UMETA( DisplayName = "First Client", ToolTip="First Client Only (and Editor)" ),
  DedicatedServer UMETA( DisplayName = "Dedicated Server", ToolTip="On dedicated server (and Editor), same as EditorOnly if bRunOnDedicatedServer is off" ),
  EditorOnly      UMETA( DisplayName = "Editor Only", ToolTip="Only in editor context for tools" ),
};

UCLASS(config = Game, defaultconfig)
class UModioSettings : public UObject
{
  GENERATED_BODY()

public:
  UModioSettings(const FObjectInitializer &ObjectInitializer);

  UPROPERTY(EditAnywhere, config, Category = Custom, meta = (UIMin = 1, ClampMin = 1))
  int32 GameId;

  UPROPERTY(EditAnywhere, config, Category = Custom)
  FString ApiKey;

  UPROPERTY(EditAnywhere, config, Category = Custom)
  FString RootDirectory;

  UPROPERTY( EditAnywhere, config, Category = Custom )
  uint8 bRootDirectoryIsInUserSettingsDirectory:1;

#if WITH_EDITORONLY_DATA
  /** Use this to define where in editor we want to run the modio instance, as we only support one logged in user per executable */
  UPROPERTY(EditAnywhere, config, Category = EditorDebug)
  ERunInEditorOn RunInEditor;
#endif
  
  /** If the instance should run on a dedicated server */
  UPROPERTY(EditAnywhere, config, Category = Custom)
  uint8 bRunOnDedicatedServer:1;

  UPROPERTY( EditAnywhere, config, Category = Custom )
  uint8 bIsLiveEnvironment:1;

  UPROPERTY( EditAnywhere, config, Category = Custom )
  uint8 bInstallOnModDownload:1;

  UPROPERTY( EditAnywhere, config, Category = Custom )
  uint8 bRetrieveModsFromOtherGames:1;

  UPROPERTY( EditAnywhere, config, Category = Custom )
  uint8 bEnablePolling:1;
};