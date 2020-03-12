<a href="https://mod.io"><img src="https://static.mod.io/v1/images/branding/modio-color-dark.svg" alt="mod.io" width="360" align="right"/></a>
# Unreal Engine 4 Plugin
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/modio/UE4Plugin/blob/master/LICENSE)
[![Discord](https://img.shields.io/discord/389039439487434752.svg?label=Discord&logo=discord&color=7289DA&labelColor=2C2F33)](https://discord.mod.io)
[![Master docs](https://img.shields.io/badge/docs-master-green.svg)](https://github.com/modio/UE4Plugin/wiki)

Welcome to [mod.io](https://mod.io) Unreal Engine 4 Plugin. It allows game developers to easily control the browsing and installation of mod files in their games. It provides a C/blueprint interface built on the Unreal Engine to connect to the [mod.io API](https://docs.mod.io). We have a [test environment](https://test.mod.io) available which offers developers a private sandbox to try the Unreal Engine 4 Plugin out.

<p align="center"><a href="https://www.unrealengine.com/marketplace/en-US/slug/mod-browser-manager"><img src="https://image.mod.io/members/c4ca/1/profileguides/unreal.png" alt="unreal" width="380" height="133"></a></p>

## Features

| Feature | Supported |
|----------|------------ |
| Windows 64bits (more platform are WIP) | ✔ |
| Standalone | ✔ |
| Open Source | ✔ |
| Free | ✔ |
| Async Callbacks | ✔ |
| Events | ✔ |
| Email / Steam / GOG authentication | ✔ |
| Prebuilt download and upload queue | ✔ |
| Mod ratings / dependencies | ✔ |
| MIT license | ✔ |

## Documentation

A quick start guide is provided below, in addition to the more [detailed wiki](https://github.com/modio/UE4Plugin/wiki). There is also an [example project](https://github.com/modio/UE4Example) showing authentication and downloading mods.

## Usage

### Browse mods

![Alt text](img/Readme/Browse.png?raw=true "Title")

```c++
FModioSortCreator SortCreator;
SortCreator.ModSortType = EModioModSortType::SORT_BY_DATE_UPDATED;
SortCreator.Ascending = false;

FModioFilterCreator FilterCreator;
FilterCreator.Sort = SortCreator;

Modio->GetAllMods(FilterCreator,
                   { TEXT("Hat"), TEXT("HD") } /* Filter by tags */,
                   4 /* Limit the number of results for a request. */,
                   0 /* Use the offset to skip over results and paginate through them */,
                   FModioModArrayDelegate::CreateUObject(ModioManager, &UModioManager::OnGetAllMods));

// ...

void UModioManager::OnGetAllMods(FModioResponse Response, const TArray<FModioMod> &Mods)
{
  for (FModioMod Mod : Mods)
  {
    UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *Mod.Name);
    UE_LOG(LogTemp, Warning, TEXT("Description: %s"), *Mod.Description);
    UE_LOG(LogTemp, Warning, TEXT("Date updated: %d"), Mod.DateUpdated);
  }
}
```

### Auth (via email)

First step is to request a security code to your email.

![Alt text](img/Readme/EmailRequest.png?raw=true "Title")

```c++
Modio->EmailRequest("john.doe@email.com", FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnEmailRequest));

// ...

void UModioManager::OnEmailRequest(FModioResponse Response)
{
  // Response.code should be 200 if an security code was sent to the provided email
}
```

Finish authentication by submitting the 5-digit code.

![Alt text](img/Readme/EmailExchange.png?raw=true "Title")

```c++
Modio->EmailExchange("VBY5A", FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnEmailExchange));

// ...

void UModioManager::OnEmailExchange(FModioResponse Response)
{
  // Response.code should be 200 if you are now authenticated
}
```

### External Auth

If your game is running inside a popular distribution platform such as Steam or GOG Galaxy you can authenticate 100% seamlessly.

#### Galaxy Auth

![Alt text](img/Readme/GalaxyAuth.png?raw=true "Title")

```c++
Modio->GalaxyAuth("csEYJ2MWR53QssNNqFgO87sRN", FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnGalaxyAuth));
// ...

void UModioManager::OnGalaxyAuth(FModioResponse Response)
{
  // Response.code should be 200 if you are now authenticated via Galaxy
}
```

#### Oculus Auth

![Alt text](img/Readme/OculusAuth.png?raw=true "Title")

```c++
Modio->OculusAuth("zBOBKszK..txDHJvjAC",// nonce proof
  3485509464809317, // User id
  "OCAf57IgZCf9JphLvM3dY...lVxWf5tenZBoOLAZDZD", // access token
  "user@email.com", // Email, optional parameter, skip with ""
  "rift", // rift and quest authentication supported
  0, // Expiry date, skip with 0
  FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnGalaxyAuth));
// ...

void UModioManager::OnGalaxyAuth(FModioResponse Response)
{
  // Response.code should be 200 if you are now authenticated via Galaxy
}
```

#### Steam Auth

You will need to setup the following:

* Add your Encrypted App Ticket Key from your Steam Partner game into your game options on the mod.io web
* In your game code, retrieve the Encrypted App Ticket from the Steamwoks SDK (or by using a Steamworks plugin of your choice)
* Also encrypt the Encrypted App Ticket under base 64 before using the mod.io `Steam Auth` function

![Alt text](img/Readme/SteamAuth.png?raw=true "Title")

```c++
Modio->SteamAuth("NDNuZmhnaWdyaGdqOWc0M2o5eTM0aGc", FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnSteamAuth));

// ...

void UModioManager::OnSteamAuth(FModioResponse Response)
{
  // Response.code should be 200 if you are now authenticated via Steam
}
```

### Subscriptions

Download and remove mods locally by subscribing and unsubscribing.

#### Subscribe

![Alt text](img/Readme/Subscribe.png?raw=true "Title")

```c++
Modio->SubscribeToMod(mod_id, FModioModDelegate::CreateUObject(ModioManager, &UModioManager::OnSubscribeToMod));

// ...

void UMyModioManager::OnSubscribeToMod(FModioResponse Response, FModioMod Mod)
{
  // Response.code should be 200 if you subscribed to the mod successfully
}
```

### Unsubscribe

![Alt text](img/Readme/Unsubscribe.png?raw=true "Title")

```c++
Modio->UnsubscribeFromMod(mod_id, FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnUnsubscribeFromMod));

// ...

void UMyModioManager::OnUnsubscribeFromMod(FModioResponse Response)
{
  // Response.code should be 200 if you unsubscribed from the mod successfully
}
```

### Mod submission

Share mods by creating a mod profile and attaching modfiles to it.

#### Create a mod profile

![Alt text](img/Readme/AddMod.png?raw=true "Title")

```c++
FModioModCreator ModCreator;
ModCreator.Name = "My Mod";
ModCreator.LogoPath = "ModExample/logo.png";
ModCreator.HomepageUrl = "http://www.webpage.com";
ModCreator.Summary = "Mod added via the SDK examples. Mod added via the SDK examples. Mod added via the SDK examples. Mod added via the SDK examples. Mod added via the SDK examples. Mod added via the SDK examples.";
Modio->AddMod(ModCreator, FModioModDelegate::CreateUObject(ModioManager, &UModioManager::OnAddMod));

// ...

void AModioManager::OnAddMod(FModioResponse Response, FModioMod Mod)
{
  // Response.code should be 200 if the mod profile was created
}
```

#### Upload a modfile

![Alt text](img/Readme/AddModfile.png?raw=true "Title")

```c++
FModioModfileCreator ModfileCreator;
ModfileCreator.Path = "ModExample/modfile/";
ModfileCreator.Version = "v1.1.0";
ModfileCreator.Changelog = "This is a change log...";

Modio->AddModfile(mod_id, ModfileCreator);
```

### Listeners

#### Download listener

![Alt text](img/Readme/DownloadListener.png?raw=true "Title")

```c++
Modio->SetModDownloadListener(FModioListenerDelegate::CreateUObject(ModioManager, &UMyModioManager::OnModDownload));

// ...

void UMyModioManager::OnModDownload(int32 ResponseCode, int32 ModId)
{
  // ResponseCode should be 200 when a mod was just downloaded
  Modio->InstallDownloadedMods();
}
```

#### Upload listener

![Alt text](img/Readme/UploadListener.png?raw=true "Title")

```c++
Modio->SetModfileUploadListener(FModioListenerDelegate::CreateUObject(ModioManager, &UMyModioManager::OnModUpload));

// ...

void UMyModioManager::OnModUpload(int32 ResponseCode, int32 ModId)
{
  // ResponseCode should be 200 when a mod was just uploaded
}
```

## Getting started
If you are a game developer, first step is to add mod support to your Unreal Engine 4 game. Once mod support is up and running, [create your games profile](https://mod.io/games/add) on mod.io, to get an API key and access to all [functionality mod.io offers](https://apps.mod.io/guides/getting-started). Next, input your `Game ID` and `API Key` under the mod.io `Project Settings` in your UE4 editor.

![Alt text](img/settings.png?raw=true "Title")

Once initialized, you are ready to start interacting with either the Blueprint layer or C++. Both have the same funcionality so it's up to you choosing what fits better to your game.

### Blueprint layer

Interact with mod.io by using the intuitive mod.io functions, callback proxies and structures. Don't forget to connect the `Process` node yo your `Tick` function for the callbacks can take effect.

![Alt text](img/blueprint_process.png?raw=true "Title")

### C++ layer

Import the mod.io subsystem and get the Subsystem pointer to start interacting with mod.io. Remeber to call `Modio->Process()` regularly to process the async funcionality.

```c++
#include "ModioSubsystem.h"

// ...

FModioSubsystemPtr Modio;
Modio = FModioSubsystem::Get(GetWorld());

// ...

void UModioManager::Tick(float DeltaTime)
{
  Modio->Process();
}
```

## Contributions Welcome
Our Unreal Engine 4 plugin is public and open source. Game developers are welcome to utilize it directly, to add support for mods in their games, or fork it for their games customized use. Want to make changes to our plugin? Submit a pull request with your recommended changes to be reviewed.

### Building

You can use the standalone `build.bat` file to compile it after you have done modification to the plugin. If you're looking for integrating mod.io to your game refer to the [Getting started](#getting-started) guide instead.

```
cd build
build.bat [UE4 VERSION]
```

Where [UE4 VERSION] is the UE4 version that will be used for building, it has to be installed on your system beforehand. The following versions are supported:

```
:: Build with UE4 v19
build.bat 19

:: Build with UE4 v20
build.bat 20

:: Build with UE4 v21
build.bat 21

:: Build with UE4 v22
build.bat 22

:: Build with UE4 v23
build.bat 22

:: Build with the latest 3 UE4 versions supported
build.bat all
```

## Other Repositories
Our aim with [mod.io](https://mod.io), is to provide an open modding API. You are welcome to [view, fork and contribute to our other codebases](https://github.com/modio) in use:

* [Design](https://design.mod.io) is public and open source, the repository can be [found here](https://github.com/modio/WebDesign).
* [API documentation](https://docs.mod.io) is public and open source, the repository can be [found here](https://github.com/modio/APIDocs).
* [Browse engine tools](https://apps.mod.io), plugins and wrappers created by the community, or [share your own](https://apps.mod.io/add).
* [Unreal Engine 4 plugin](https://github.com/modio/UE4Plugin), easily manage the browsing and install of mods in Unreal Engine 4 games
* [Unity Engine plugin](https://github.com/modio/UnityPlugin), easily manage the browsing and install of mods in Unity Engine games
* [Python wrapper](https://github.com/ClementJ18/mod.io), a python wrapper for the mod.io API
* [Rust wrapper](https://github.com/nickelc/modio-rs), rust interface for mod.io
* And more...
