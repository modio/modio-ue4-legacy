#include "FModioMod.h"

void initializeMod(FModioMod &mod, modio::Mod modio_mod)
{
  mod.Id = modio_mod.id;
  mod.GameId = modio_mod.game_id;
  mod.Status = modio_mod.status;
  mod.Visible = modio_mod.visible;
  mod.MaturityOption = modio_mod.maturity_option;
  mod.DateAdded = modio_mod.date_added;
  mod.DateUpdated = modio_mod.date_updated;
  mod.DateLive = modio_mod.date_live;
  mod.HomepageUrl = UTF8_TO_TCHAR(modio_mod.homepage_url.c_str());
  mod.Name = UTF8_TO_TCHAR(modio_mod.name.c_str());
  mod.NameId = UTF8_TO_TCHAR(modio_mod.name_id.c_str());
  mod.Summary = UTF8_TO_TCHAR(modio_mod.summary.c_str());
  mod.Description = UTF8_TO_TCHAR(modio_mod.description.c_str());
  mod.DescriptionPlainText = UTF8_TO_TCHAR(modio_mod.description_plaintext.c_str());
  mod.MetadataBlob = UTF8_TO_TCHAR(modio_mod.metadata_blob.c_str());
  mod.ProfileUrl = UTF8_TO_TCHAR(modio_mod.profile_url.c_str());
  initializeLogo(mod.Logo, modio_mod.logo);
  initializeUser(mod.SubmittedBy, modio_mod.submitted_by);
  initializeModfile(mod.Modfile, modio_mod.modfile);
  initializeMedia(mod.Media, modio_mod.media);
  initializeStats(mod.Stats, modio_mod.stats);

  for (u32 i = 0; i < modio_mod.tags.size(); i++)
  {
    FModioTag tag;
    initializeTag(tag, modio_mod.tags[i]);
    mod.Tags.Add(tag);
  }

  for (u32 i = 0; i < modio_mod.metadata_kvps.size(); i++)
  {
    FModioMetadataKVP metadata_kvp;
    initializeMetadataKVP(metadata_kvp, modio_mod.metadata_kvps[i]);
    mod.MetadataKVP.Add(metadata_kvp);
  }
}

void initializeModC(FModioMod &mod, ModioMod modio_mod)
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
  initializeLogoC(mod.Logo, modio_mod.logo);
  initializeUserC(mod.SubmittedBy, modio_mod.submitted_by);
  initializeModfileC(mod.Modfile, modio_mod.modfile);
  initializeMediaC(mod.Media, modio_mod.media);
  initializeStatsC(mod.Stats, modio_mod.stats);

  for (u32 i = 0; i < modio_mod.tags_array_size; i++)
  {
    FModioTag tag;
    initializeTagC(tag, modio_mod.tags_array[i]);
    mod.Tags.Add(tag);
  }

  for (u32 i = 0; i < modio_mod.metadata_kvp_array_size; i++)
  {
    FModioMetadataKVP metadata_kvp;
    initializeMetadataKVPC(metadata_kvp, modio_mod.metadata_kvp_array[i]);
    mod.MetadataKVP.Add(metadata_kvp);
  }
}