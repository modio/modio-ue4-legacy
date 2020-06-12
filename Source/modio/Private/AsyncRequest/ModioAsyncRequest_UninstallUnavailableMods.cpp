// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "AsyncRequest/ModioAsyncRequest_UninstallUnavailableMods.h"
#include "ModioUE4Utility.h"

FModioAsyncRequest_UninstallUnavailableMods::FModioAsyncRequest_UninstallUnavailableMods( FModioSubsystem *Modio, FModioGenericDelegate Delegate, int32 PendingCalls ) :
  FModioAsyncRequest( Modio ),
  ResponseDelegate( Delegate )
{
  this->PendingCalls = PendingCalls;
}

TArray<int32> getInstalledMods()
{
  TArray<int32> InstalledMods;
  u32 installed_mods_count = modioGetAllInstalledModsCount();
  ModioInstalledMod *modio_installed_mods = (ModioInstalledMod *)malloc(installed_mods_count * sizeof(*modio_installed_mods));
  modioGetAllInstalledMods(modio_installed_mods);
  for (u32 i = 0; i < installed_mods_count; i++)
  {
    InstalledMods.Add(modio_installed_mods[i].mod.id);
    modioFreeInstalledMod(&modio_installed_mods[i]);
  }
  free(modio_installed_mods);
  return InstalledMods;
}

void FModioAsyncRequest_UninstallUnavailableMods::Response(void *Object, ModioResponse ModioResponse, ModioMod *ModioMods, u32 ModioModsSize)
{
  UE_LOG(LogTemp, Warning, TEXT("[mod.io] FModioAsyncRequest_UninstallUnavailableMods response returned"));
  FModioAsyncRequest_UninstallUnavailableMods* ThisPointer = (FModioAsyncRequest_UninstallUnavailableMods*)Object;

  ThisPointer->PendingCalls--;
  for(int32 i=0; i<(int32)ModioModsSize; i++)
  {
    ThisPointer->AvailableMods.Push(ModioMods[i].id);
  }
  
  if(ThisPointer->PendingCalls == 0)
  {
    UE_LOG(LogTemp, Warning, TEXT("[mod.io] FModioAsyncRequest_UninstallUnavailableMods response returned"));
    for(auto InstalledMod : getInstalledMods())
    {
      bool IsAvailable = false;
      for(auto AvailableMod : ThisPointer->AvailableMods)
      {
        if(InstalledMod == AvailableMod)
          IsAvailable = true;
      }
      if(!IsAvailable)
      {
        UE_LOG(LogTemp, Warning, TEXT("[mod.io] Mod %i is unavailable, will be uninstalled"), InstalledMod);
        modioUninstallMod((u32)InstalledMod);
      }else
      {
        UE_LOG(LogTemp, Warning, TEXT("[mod.io] Mod %i is available"), InstalledMod);
      }
    }
    FModioResponse Response;
    InitializeResponse( Response, ModioResponse );

    ThisPointer->ResponseDelegate.ExecuteIfBound( Response );
    
    ThisPointer->Done();
  }
}