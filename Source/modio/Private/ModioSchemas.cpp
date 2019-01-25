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