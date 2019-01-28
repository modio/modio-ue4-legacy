#include "ModioSchemas.h"

void initializeLogo(FModioLogo &Logo, modio::Logo modio_logo)
{
  Logo.Filename = UTF8_TO_TCHAR(modio_logo.filename.c_str());
  Logo.Original = UTF8_TO_TCHAR(modio_logo.original.c_str());
  Logo.Thumb320x180 = UTF8_TO_TCHAR(modio_logo.thumb_320x180.c_str());
  Logo.Thumb640x360 = UTF8_TO_TCHAR(modio_logo.thumb_640x360.c_str());
  Logo.Thumb1280x720 = UTF8_TO_TCHAR(modio_logo.thumb_1280x720.c_str());
}

void initializeLogoC(FModioLogo &Logo, ModioLogo modio_logo)
{
  Logo.Filename = UTF8_TO_TCHAR(modio_logo.filename);
  Logo.Original = UTF8_TO_TCHAR(modio_logo.original);
  Logo.Thumb320x180 = UTF8_TO_TCHAR(modio_logo.thumb_320x180);
  Logo.Thumb640x360 = UTF8_TO_TCHAR(modio_logo.thumb_640x360);
  Logo.Thumb1280x720 = UTF8_TO_TCHAR(modio_logo.thumb_1280x720);
}

void initializeAvatar(FModioAvatar &Avatar, modio::Avatar modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename.c_str());
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original.c_str());
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50.c_str());
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100.c_str());
}

void initializeAvatarC(FModioAvatar &Avatar, ModioAvatar modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename);
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original);
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50);
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100);
}

void initializeUser(FModioUser &User, modio::User modio_user)
{
  User.Id = modio_user.id;
  User.DateOnline = modio_user.date_online;
  User.Username = UTF8_TO_TCHAR(modio_user.username.c_str());
  User.NameId = UTF8_TO_TCHAR(modio_user.name_id.c_str());
  User.Timezone = UTF8_TO_TCHAR(modio_user.timezone.c_str());
  User.Language = UTF8_TO_TCHAR(modio_user.language.c_str());
  User.ProfileUrl = UTF8_TO_TCHAR(modio_user.profile_url.c_str());
  initializeAvatar(User.Avatar, modio_user.avatar);
}

void initializeUserC(FModioUser &User, ModioUser modio_user)
{
  User.Id = modio_user.id;
  User.DateOnline = modio_user.date_online;
  User.Username = UTF8_TO_TCHAR(modio_user.username);
  User.NameId = UTF8_TO_TCHAR(modio_user.name_id);
  User.Timezone = UTF8_TO_TCHAR(modio_user.timezone);
  User.Language = UTF8_TO_TCHAR(modio_user.language);
  User.ProfileUrl = UTF8_TO_TCHAR(modio_user.profile_url);
  initializeAvatarC(User.Avatar, modio_user.avatar);
}

void initializeFilehash(FModioFilehash &Filehash, modio::Filehash modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5.c_str());
}

void initializeFilehashC(FModioFilehash &Filehash, ModioFilehash modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5);
}

void initializeDownload(FModioDownload &Download, modio::Download modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url.c_str());
}

void initializeDownloadC(FModioDownload &Download, ModioDownload modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url);
}

void initializeModfile(FModioModfile &Modfile, modio::Modfile modio_modfile)
{
  Modfile.Id = modio_modfile.id;
  Modfile.ModId = modio_modfile.mod_id;
  Modfile.VirusStats = modio_modfile.virus_status;
  Modfile.VirusPositive = modio_modfile.virus_positive;
  Modfile.DateAdded = modio_modfile.date_added;
  Modfile.DateScanned = modio_modfile.date_scanned;
  Modfile.Filesize = modio_modfile.filesize;
  Modfile.Filename = UTF8_TO_TCHAR(modio_modfile.filename.c_str());
  Modfile.Version = UTF8_TO_TCHAR(modio_modfile.version.c_str());
  Modfile.VirustotalHash = UTF8_TO_TCHAR(modio_modfile.virustotal_hash.c_str());
  Modfile.Changelog = UTF8_TO_TCHAR(modio_modfile.changelog.c_str());
  Modfile.MetadataBlob = UTF8_TO_TCHAR(modio_modfile.metadata_blob.c_str());
  initializeFilehash(Modfile.Filehash, modio_modfile.filehash);
  initializeDownload(Modfile.Download, modio_modfile.download);
}

void initializeModfileC(FModioModfile &Modfile, ModioModfile modio_modfile)
{
  Modfile.Id = modio_modfile.id;
  Modfile.ModId = modio_modfile.mod_id;
  Modfile.VirusStats = modio_modfile.virus_status;
  Modfile.VirusPositive = modio_modfile.virus_positive;
  Modfile.DateAdded = modio_modfile.date_added;
  Modfile.DateScanned = modio_modfile.date_scanned;
  Modfile.Filesize = modio_modfile.filesize;
  Modfile.Filename = UTF8_TO_TCHAR(modio_modfile.filename);
  Modfile.Version = UTF8_TO_TCHAR(modio_modfile.version);
  Modfile.VirustotalHash = UTF8_TO_TCHAR(modio_modfile.virustotal_hash);
  Modfile.Changelog = UTF8_TO_TCHAR(modio_modfile.changelog);
  Modfile.MetadataBlob = UTF8_TO_TCHAR(modio_modfile.metadata_blob);
  initializeFilehashC(Modfile.Filehash, modio_modfile.filehash);
  initializeDownloadC(Modfile.Download, modio_modfile.download);
}

void initializeImage(FModioImage &Image, modio::Image modio_image)
{
  Image.Filename = UTF8_TO_TCHAR(modio_image.filename.c_str());
  Image.Original = UTF8_TO_TCHAR(modio_image.original.c_str());
  Image.Thumb320x180 = UTF8_TO_TCHAR(modio_image.thumb_320x180.c_str());
}

void initializeImageC(FModioImage &Image, ModioImage modio_image)
{
  Image.Filename = UTF8_TO_TCHAR(modio_image.filename);
  Image.Original = UTF8_TO_TCHAR(modio_image.original);
  Image.Thumb320x180 = UTF8_TO_TCHAR(modio_image.thumb_320x180);
}

void initializeMedia(FModioMedia &media, modio::Media modio_media)
{
  for (u32 i = 0; i < modio_media.youtube.size(); i++)
    media.Youtube.Add(UTF8_TO_TCHAR(modio_media.youtube[i].c_str()));
  for (u32 i = 0; i < modio_media.sketchfab.size(); i++)
    media.Sketchfab.Add(UTF8_TO_TCHAR(modio_media.sketchfab[i].c_str()));
  for (u32 i = 0; i < modio_media.images.size(); i++)
  {
    FModioImage image;
    initializeImage(image, modio_media.images[i]);
    media.Images.Add(image);
  }
}

void initializeMediaC(FModioMedia &media, ModioMedia modio_media)
{
  for (u32 i = 0; i < modio_media.youtube_size; i++)
    media.Youtube.Add(UTF8_TO_TCHAR(modio_media.youtube_array[i]));
  for (u32 i = 0; i < modio_media.sketchfab_size; i++)
    media.Sketchfab.Add(UTF8_TO_TCHAR(modio_media.sketchfab_array[i]));
  for (u32 i = 0; i < modio_media.images_size; i++)
  {
    FModioImage image;
    initializeImageC(image, modio_media.images_array[i]);
    media.Images.Add(image);
  }
}

void initializeStats(FModioStats &Stats, modio::Stats modio_stats)
{
  Stats.ModId = modio_stats.mod_id;
  Stats.PopularityRankPosition = modio_stats.popularity_rank_position;
  Stats.PopularityRankTotalMods = modio_stats.popularity_rank_total_mods;
  Stats.DownloadsTotal = modio_stats.downloads_total;
  Stats.SubscribersTotal = modio_stats.subscribers_total;
  Stats.RatingsTotal = modio_stats.ratings_total;
  Stats.RatingsPositive = modio_stats.ratings_positive;
  Stats.RatingsNegative = modio_stats.ratings_negative;
  Stats.RatingsPercentagePositive = modio_stats.ratings_percentage_positive;
  Stats.RatingsWeightedAggregate = modio_stats.ratings_weighted_aggregate;
  Stats.DateExpires = modio_stats.date_expires;
  Stats.RatingsDisplayText = UTF8_TO_TCHAR(modio_stats.ratings_display_text.c_str());
}

void initializeStatsC(FModioStats &Stats, ModioStats modio_stats)
{
  Stats.ModId = modio_stats.mod_id;
  Stats.PopularityRankPosition = modio_stats.popularity_rank_position;
  Stats.PopularityRankTotalMods = modio_stats.popularity_rank_total_mods;
  Stats.DownloadsTotal = modio_stats.downloads_total;
  Stats.SubscribersTotal = modio_stats.subscribers_total;
  Stats.RatingsTotal = modio_stats.ratings_total;
  Stats.RatingsPositive = modio_stats.ratings_positive;
  Stats.RatingsNegative = modio_stats.ratings_negative;
  Stats.RatingsPercentagePositive = modio_stats.ratings_percentage_positive;
  Stats.RatingsWeightedAggregate = modio_stats.ratings_weighted_aggregate;
  Stats.DateExpires = modio_stats.date_expires;
  Stats.RatingsDisplayText = UTF8_TO_TCHAR(modio_stats.ratings_display_text);
}

void initializeTag(FModioTag &Tag, modio::Tag modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name.c_str());
}

void initializeTagC(FModioTag &Tag, ModioTag modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name);
}

void initializeMetadataKVP(FModioMetadataKVP &MetadataKVP, modio::MetadataKVP modio_metadata_kvp)
{
  MetadataKVP.Metakey = UTF8_TO_TCHAR(modio_metadata_kvp.metakey.c_str());
  MetadataKVP.Metavalue = UTF8_TO_TCHAR(modio_metadata_kvp.metavalue.c_str());
}

void initializeMetadataKVPC(FModioMetadataKVP &MetadataKVP, ModioMetadataKVP modio_metadata_kvp)
{
  MetadataKVP.Metakey = UTF8_TO_TCHAR(modio_metadata_kvp.metakey);
  MetadataKVP.Metavalue = UTF8_TO_TCHAR(modio_metadata_kvp.metavalue);
}

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

void initializeInstalledModC(FModioInstalledMod &installed_mod, ModioInstalledMod modio_installed_mod)
{
  installed_mod.Path = UTF8_TO_TCHAR(modio_installed_mod.path);
  initializeModC(installed_mod.mod, modio_installed_mod.mod);
}

void initializeQueuedModDownloadC(FModioQueuedModDownload &queued_mod_download, ModioQueuedModDownload modio_queued_mod_download)
{
  queued_mod_download.Path = UTF8_TO_TCHAR(modio_queued_mod_download.path);
  queued_mod_download.CurrentProgress = modio_queued_mod_download.current_progress;
  queued_mod_download.TotalSize = modio_queued_mod_download.total_size;
  initializeModC(queued_mod_download.mod, modio_queued_mod_download.mod);
}

void initializeQueuedModfileUploadC(FModioQueuedModfileUpload &queued_modfile_upload, ModioQueuedModfileUpload modio_queued_modfile_upload)
{
  queued_modfile_upload.State = modio_queued_modfile_upload.state;
  queued_modfile_upload.ModId = modio_queued_modfile_upload.mod_id;
  queued_modfile_upload.CurrentProgress = modio_queued_modfile_upload.current_progress;
  queued_modfile_upload.TotalSize = modio_queued_modfile_upload.total_size;
  queued_modfile_upload.Path = UTF8_TO_TCHAR(modio_queued_modfile_upload.path);
}