<a href="https://mod.io"><img src="https://static.mod.io/v1/images/branding/modio-color-dark.svg" alt="mod.io" width="400"/></a>

# Unreal Engine 4 Plugin
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/modio/UE4Plugin/blob/master/LICENSE)
[![Discord](https://img.shields.io/discord/389039439487434752.svg?label=Discord&logo=discord&color=7289DA&labelColor=2C2F33)](https://discord.mod.io)
[![Master docs](https://img.shields.io/badge/docs-master-green.svg)](https://github.com/modio/UE4Plugin/wiki)


Welcome to [mod.io](https://mod.io) Unreal Engine 4 Plugin. It allows game developers to easily control the browsing and installation of mod files in their games. It provides a C/blueprint interface built on the Unreal Engine to connect to the [mod.io API](https://docs.mod.io). We have a [test environment](https://test.mod.io) available which offers developers a private sandbox to try the Unreal Engine 4 Plugin out.

## Usage

### Browse mods

```
Modio->GetAllMods(EModioFilterType::SORT_BY_DATE_UPDATED,
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

```
Modio->EmailRequest("john.doe@email.com", FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnEmailRequest));

// ...

void UModioManager::OnEmailRequest(FModioResponse Response)
{
  // Response.code should be 200 if an security code was sent to the provided email
}
```

Finish authentication by submitting the 5-digit code.

```
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

```
Modio->GalaxyAuth("csEYJ2MWR53QssNNqFgO87sRN", FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnGalaxyAuth));

// ...

void UModioManager::OnGalaxyAuth(FModioResponse Response)
{
  // Response.code should be 200 if you are now authenticated via Galaxy
}
```

#### Steam Auth

```
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

```
Modio->SubscribeToMod(153, FModioModDelegate::CreateUObject(ModioManager, &UModioManager::OnSubscribeToMod));

// ...

void UMyModioManager::OnSubscribeToMod(FModioResponse Response, FModioMod Mod)
{
  // Response.code should be 200 if you subscribed to the mod successfully
}
```

### Unsubscribe

```
Modio->UnsubscribeFromMod(153, FModioGenericDelegate::CreateUObject(ModioManager, &UModioManager::OnUnsubscribeFromMod));

// ...

void UMyModioManager::OnUnsubscribeFromMod(FModioResponse Response)
{
  // Response.code should be 200 if you unsubscribed from the mod successfully
}
```

### Mod submission

Share mods by creating a mod profile and attaching modfiles to it.

#### Create a mod profile

```
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

```
FModioModfileCreator ModfileCreator;
ModfileCreator.Path = "ModExample/modfile/";
ModfileCreator.Version = "v1.1.0";
ModfileCreator.Changelog = "This is a change log...";

Modio->AddModfile(132, ModfileCreator);
```

### Listeners

#### Download listener

```
Modio->SetModDownloadListener(FModioOnModDownloadDelegate::CreateUObject(ModioManager, &UMyModioManager::OnModDownload));

// ...

void UMyModioManager::OnModDownload(int32 ResponseCode, int32 ModId)
{
  // ResponseCode should be 200 when a mod was just downloaded
  Modio->InstallDownloadedMods();
}
```

#### Upload listener

```
Modio->SetModUploadListener(FModioOnModDownloadDelegate::CreateUObject(ModioManager, &UMyModioManager::OnModUpload));

// ...

void UMyModioManager::OnModUpload(int32 ResponseCode, int32 ModId)
{
  // ResponseCode should be 200 when a mod was just uploaded
}
```

## Getting started
If you are a game developer, first step is to add mod support to your Unreal Engine 4 game. Once mod support is up and running, [create your games profile](https://mod.io/games/add) on mod.io, to get an API key and access to all [functionality mod.io offers](https://apps.mod.io/guides/getting-started).
Next, download the latest [UE4 release](https://github.com/modio/UE4Plugin/releases) and unpack it into your project, then head over to the [GitHub Wiki](https://github.com/modio/UE4Plugin/wiki) and follow the guides to get it running within your game.

![Alt text](img/settings.png?raw=true "Title")

```
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

## Other Repositories
Our aim with [mod.io](https://mod.io), is to provide an open modding API. You are welcome to [view, fork and contribute to our other codebases](https://github.com/modio) in use:

* [Design](https://design.mod.io) is public and open source, the repository can be [found here](https://github.com/modio/WebDesign).
* [API documentation](https://docs.mod.io) is public and open source, the repository can be [found here](https://github.com/modio/APIDocs).
* [Browse engine tools](https://apps.mod.io), plugins and wrappers created by the community, or [share your own](https://apps.mod.io/add).
* [Unity Engine plugin](https://github.com/modio/UnityPlugin), easily manage the browsing and install of mods in Unity Engine games
* [Python wrapper](https://github.com/ClementJ18/mod.io), a python wrapper for the mod.io API
* [Rust wrapper](https://github.com/nickelc/modio-rs), rust interface for mod.io
* And more...
