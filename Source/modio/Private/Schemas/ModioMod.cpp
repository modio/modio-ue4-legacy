// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioMod.h"

void InitializeMod(FModioMod &mod, const ModioMod &modio_mod)
{
  mod.Id = modio_mod.id;
  mod.GameId = modio_mod.game_id;
  mod.Status = modio_mod.status;
  mod.Visible = modio_mod.visible;
  mod.MaturityOption = modio_mod.maturity_option;
  mod.DateAdded = modio_mod.date_added;
  mod.DateUpdated = modio_mod.date_updated;
  mod.DateLive = modio_mod.date_live;
  mod.HomepageUrl = UTF8_TO_TCHAR(modio_mod.homepage_url);
  mod.Name = UTF8_TO_TCHAR(modio_mod.name);
  mod.NameId = UTF8_TO_TCHAR(modio_mod.name_id);
  mod.Summary = UTF8_TO_TCHAR(modio_mod.summary);
  mod.Description = UTF8_TO_TCHAR(modio_mod.description);
  mod.DescriptionPlainText = UTF8_TO_TCHAR(modio_mod.description_plaintext);
  mod.MetadataBlob = UTF8_TO_TCHAR(modio_mod.metadata_blob);
  mod.ProfileUrl = UTF8_TO_TCHAR(modio_mod.profile_url);
  InitializeLogo(mod.Logo, modio_mod.logo);
  InitializeUser(mod.SubmittedBy, modio_mod.submitted_by);
  InitializeModfile(mod.Modfile, modio_mod.modfile);
  InitializeMedia(mod.Media, modio_mod.media);
  InitializeStats(mod.Stats, modio_mod.stats);

  for (u32 i = 0; i < modio_mod.tags_array_size; i++)
  {
    FModioModTag tag;
    InitializeModTag(tag, modio_mod.tags_array[i]);
    mod.Tags.Add(tag);
  }

  for (u32 i = 0; i < modio_mod.metadata_kvp_array_size; i++)
  {
    FModioMetadataKVP metadata_kvp;
    InitializeMetadataKVP(metadata_kvp, modio_mod.metadata_kvp_array[i]);
    mod.MetadataKVP.Add(metadata_kvp);
  }
}