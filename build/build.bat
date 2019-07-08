@ECHO OFF

IF %1.==. (
    GOTO NOPARAM
) ELSE (
    GOTO BUILD
)

:BUILD

IF %1 == 19 (
    ECHO Building the mod.io plugin with UE4 v19
    "C:\Program Files\Epic Games\UE_4.19\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_419" -Rocket
) ELSE IF %1 == 20 (
    ECHO Building the mod.io plugin with UE4 v20
    "C:\Program Files\Epic Games\UE_4.20\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_420" -Rocket
) ELSE IF %1 == 21 (
    ECHO Building the mod.io plugin with UE4 v21
    "C:\Program Files\Epic Games\UE_4.21\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_421" -Rocket
) ELSE IF %1 == 22 (
    ECHO Building the mod.io plugin with UE4 v22
    "C:\Program Files\Epic Games\UE_4.22\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_422" -Rocket
) ELSE IF %1 == all (
    ECHO Building the mod.io plugin with UE4 v19, v20, v21, v22
    "C:\Program Files\Epic Games\UE_4.19\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_419" -Rocket
    "C:\Program Files\Epic Games\UE_4.20\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_420" -Rocket
    "C:\Program Files\Epic Games\UE_4.21\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_421" -Rocket
    "C:\Program Files\Epic Games\UE_4.22\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%CD%\..\modio.uplugin" -TargetPlatforms=Win64 -Package="%CD%\PluginStaging_ALL\modio_UE4_422" -Rocket
) ELSE (
    ECHO Version %1 not supported by this script
    ECHO The following versions param is allowed v19, v20, v21, v22 and all
)

GOTO DONE

:NOPARAM
ECHO NoParam!
GOTO DONE

:DONE
ECHO Done!