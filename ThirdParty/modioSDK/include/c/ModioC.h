#ifndef MODIO_MODIO_C_H
#define MODIO_MODIO_C_H

typedef unsigned int u32;
typedef int i32;

#define MODIO_ENVIRONMENT_LIVE 0
#define MODIO_ENVIRONMENT_TEST 1

#define MODIO_DEBUGLEVEL_LOG      2
#define MODIO_DEBUGLEVEL_WARNING  1
#define MODIO_DEBUGLEVEL_ERROR    0

#define MODIO_MODFILE_NOT_INSTALLED 0
#define MODIO_MODFILE_INSTALLED     1
#define MODIO_MODFILE_INSTALLING    2

// Status Constants
#define MODIO_NOT_ACCEPTED 0
#define MODIO_ACCEPTED     1
#define MODIO_ARCHIVED     2
#define MODIO_DELETED      3

#define MODIO_HIDDEN 0
#define MODIO_PUBLIC 1

#define MODIO_EVENT_UNDEFINED         0
#define MODIO_EVENT_MODFILE_CHANGED   1
#define MODIO_EVENT_MOD_AVAILABLE     2
#define MODIO_EVENT_MOD_UNAVAILABLE   3
#define MODIO_EVENT_MOD_EDITED        4
#define MODIO_EVENT_USER_TEAM_JOIN    5
#define MODIO_EVENT_USER_TEAM_LEAVE   6
#define MODIO_EVENT_USER_SUBSCRIBE    7
#define MODIO_EVENT_USER_UNSUBSCRIBE  8

// Presentation Option Constants
#define MODIO_GRID_VIEW   0
#define MODIO_TABLE_VIEW  1

// Submission Option Constants
#define MODIO_MOD_UPLOADS_CONTROLED     0
#define MODIO_MOD_UPLOADS_FROM_ANYWHERE 1

// Curation Option Constants
#define MODIO_NO_CURATION   0
#define MODIO_PAID_CURATION 1
#define MODIO_FULL_CURATION 2

#define MODIO_ALL_OPTIONS_DISABLED  0

// Community Options Constants
#define MODIO_DISCUSSION_BOARD_ENABLED  1
#define MODIO_GUIDES_AND_NEWS_ENABLED   2

// Revenue Options Constants
#define MODIO_ALLOW_MODS_TO_BE_SOLD                     1
#define MODIO_ALLOW_MODS_TO_RECEIVE_DONATIONS           2
#define MODIO_ALLOW_MODS_TO_BE_TRADED                   4
#define MODIO_ALLOW_MODS_TO_CONTROL_SUPPLY_AND_SCARCITY 8

// API Access Options Constants
#define MODIO_ALLOW_ACCESS_FROM_3RD_PARTIES         1
#define MODIO_ALLOW_MODS_TO_BE_DOWNLOADED_DIRECTLY  2

// Automatic Updated Options
#define MODIO_UPDATES_DISABLED  0
#define MODIO_UPDATES_ENABLED   1

// Report Types
#define MODIO_GENERIC_REPORT  0
#define MODIO_DMCA_REPORT     1

// Mod states
#define MODIO_MOD_UNDEFINED               0
#define MODIO_MOD_NOT_INSTALLED           1
#define MODIO_MOD_QUEUED                  2
#define MODIO_MOD_STARTING_DOWNLOAD       3
#define MODIO_MOD_DOWNLOADING             4
#define MODIO_MOD_PAUSING                 5
#define MODIO_MOD_PAUSED                  6
#define MODIO_MOD_EXTRACTING              7
#define MODIO_MOD_INSTALLED               8
#define MODIO_PRIORITIZING_OTHER_DOWNLOAD 9
#define MODIO_MOD_STARTING_UPLOAD         10
#define MODIO_MOD_UPLOADING               11

// Maturity options
#define MODIO_MATURITY_NONE     0
#define MODIO_MATURITY_ALCOHOL  1
#define MODIO_MATURITY_DRUGS    2
#define MODIO_MATURITY_VIOLENCE 4
#define MODIO_MATURITY_EXPLICIT 8

extern "C"
{
  typedef struct ModioListNode ModioListNode;
  typedef struct ModioAvatar ModioAvatar;
  typedef struct ModioComment ModioComment;
  typedef struct ModioDependency ModioDependency;
  typedef struct ModioError ModioError;
  typedef struct ModioFilehash ModioFilehash;
  typedef struct ModioGame ModioGame;
  typedef struct ModioGameTagOption ModioGameTagOption;
  typedef struct ModioHeader ModioHeader;
  typedef struct ModioIcon ModioIcon;
  typedef struct ModioImage ModioImage;
  typedef struct ModioInstalledMod ModioInstalledMod;
  typedef struct ModioLogo ModioLogo;
  typedef struct ModioMedia ModioMedia;
  typedef struct ModioMetadataKVP ModioMetadataKVP;
  typedef struct ModioUser ModioUser;
  typedef struct ModioDownload ModioDownload;
  typedef struct ModioModfile ModioModfile;
  typedef struct ModioRatingSummary ModioRatingSummary;
  typedef struct ModioTag ModioTag;
  typedef struct ModioMod ModioMod;
  typedef struct ModioResponse ModioResponse;
  typedef struct ModioFilterCreator ModioFilterCreator;
  typedef struct ModioModfileCreator ModioModfileCreator;
  typedef struct ModioModfileEditor ModioModfileEditor;
  typedef struct ModioModCreator ModioModCreator;
  typedef struct ModioModEditor ModioModEditor;
  typedef struct ModioEvent ModioEvent;
  typedef struct ModioQueuedModDownload ModioQueuedModDownload;
  typedef struct ModioQueuedModfileUpload ModioQueuedModfileUpload;

  struct ModioListNode
  {
    char* value;
    ModioListNode* next;
  };

  struct ModioAvatar
  {
    char* filename;
    char* original;
    char* thumb_50x50;
    char* thumb_100x100;
  };

  struct ModioDependency
  {
    u32 mod_id;
    u32 date_added;
  };

  struct ModioError
  {
    u32 code;
    char* message;
    char** errors_array;
    u32 errors_array_size;
  };

  struct ModioFilehash
  {
    char* md5;
  };

  struct ModioHeader
  {
    char* filename;
    char* original;
  };

  struct ModioIcon
  {
    char* filename;
    char* original;
    char* thumb_64x64;
    char* thumb_128x128;
    char* thumb_256x256;
  };

  struct ModioImage
  {
    char* filename;
    char* original;
    char* thumb_320x180;
  };

  struct ModioLogo
  {
    char* filename;
    char* original;
    char* thumb_320x180;
    char* thumb_640x360;
    char* thumb_1280x720;
  };

  struct ModioMedia
  {
    char** youtube_array;
    u32 youtube_size;
    char** sketchfab_array;
    u32 sketchfab_size;
    ModioImage* images_array;
    u32 images_size;
  };

  struct ModioMetadataKVP
  {
    char* metakey;
    char* metavalue;
  };

  struct ModioUser
  {
    u32 id;
    u32 date_online;
    char* username;
    char* name_id;
    char* timezone;
    char* language;
    char* profile_url;
    ModioAvatar avatar;
  };

  struct ModioDownload
  {
    char* binary_url;
    u32 date_expires;
  };

  struct ModioModfile
  {
    u32 id;
    u32 mod_id;
    u32 virus_status;
    u32 virus_positive;
    u32 date_added;
    u32 date_scanned;
    long filesize;
    char* filename;
    char* version;
    char* virustotal_hash;
    char* changelog;
    ModioFilehash filehash;
    ModioDownload download;
  };

  struct ModioRatingSummary
  {
    u32 total_ratings;
    u32 positive_ratings;
    u32 negative_ratings;
    u32 percentage_positive;
    double weighted_aggregate;
    char* display_text;
  };

  struct ModioTag
  {
    u32 date_added;
    char* name;
  };

  struct ModioMod
  {
    u32 id;
    u32 game_id;
    u32 status;
    u32 visible;
    u32 maturity_option;
    u32 date_added;
    u32 date_updated;
    u32 date_live;
    char* homepage_url;
    char* name;
    char* name_id;
    char* summary;
    char* description;
    char* metadata_blob;
    char* profile_url;
    ModioLogo logo;
    ModioUser submitted_by;
    ModioModfile modfile;
    ModioMedia media;
    ModioRatingSummary rating_summary;
    ModioTag* tags_array;
    u32 tags_array_size;
    ModioMetadataKVP* metadata_kvp_array;
    u32 metadata_kvp_array_size;
  };

  struct ModioResponse
  {
    u32 code;
    u32 result_count;
    u32 result_limit;
    i32 result_offset;
    bool result_cached;
    ModioError error;
  };

  struct ModioFilterCreator
  {
    char* sort;
    char* limit;
    char* offset;
    char* full_text_search;
    u32 cache_max_age_seconds;
    ModioListNode* field_value_list;
    ModioListNode* like_list;
    ModioListNode* not_like_list;
    ModioListNode* in_list;
    ModioListNode* not_in_list;
    ModioListNode* min_list;
    ModioListNode* max_list;
    ModioListNode* smaller_than_list;
    ModioListNode* greater_than_list;
    ModioListNode* not_equal_list;
  };

  struct ModioModfileCreator
  {
    char* path;
    char* version;
    char* changelog;
    char* active;
    char* filehash;
  };

  struct ModioModfileEditor
  {
    char* version;
    char* changelog;
    char* active;
  };

  struct ModioModCreator
  {
    char* visible;
    char* maturity_option;
    char* logo;
    char* name;
    char* name_id;
    char* summary;
    char* description;
    char* homepage_url;
    char* metadata_blob;
    ModioListNode* tags;
  };

  struct ModioModEditor
  {
    char* visible;
    char* status;
    char* maturity_option;
    char* name;
    char* name_id;
    char* summary;
    char* description;
    char* homepage_url;
    char* modfile;
    char* metadata_blob;
  };

  struct ModioEvent
  {
    u32 id;
    u32 mod_id;
    u32 user_id;
    u32 event_type;
    u32 date_added;
  };

  struct ModioGameTagOption
  {
    u32 hidden;
    char* name;
    char* type;
    char** tags_array;
    u32 tags_array_size;
  };

  struct ModioGame
  {
    u32 id;
    u32 status;
    u32 date_added;
    u32 date_updated;
    u32 presentation_option;
    u32 date_live;
    u32 community_options;
    u32 submission_option;
    u32 curation_option;
    u32 revenue_options;
    u32 api_access_options;
    u32 maturity_options;
    char* ugc_name;
    char* instructions_url;
    char* name;
    char* name_id;
    char* summary;
    char* instructions;
    char* profile_url;
    ModioUser submitted_by;
    ModioIcon icon;
    ModioLogo logo;
    ModioHeader header;
    ModioGameTagOption* game_tag_option_array;
    u32 game_tag_option_array_size;
  };

  struct ModioInstalledMod
  {
	  u32 mod_id;
	  u32 modfile_id;
	  u32 updated_at;
	  char* path;
	  ModioMod mod;
  };

  struct ModioQueuedModDownload
  {
    u32 state;
    u32 mod_id;
    double current_progress;
    double total_size;
    char* url;
    char* path;
    ModioMod mod;
  };

  struct ModioQueuedModfileUpload
  {
    u32 state;
    u32 mod_id;
    double current_progress;
    double total_size;
    char* path;
    ModioModfileCreator modio_modfile_creator;
  };

  struct ModioComment
  {
    u32 id;
    u32 mod_id;
    ModioUser submitted_by;
    u32 date_added;
    u32 reply_id;
    u32 karma;
    u32 karma_guest;
    char* thread_position;
    char* content;
  };

  //General Methods
  void MODIO_DLL modioInit(u32 environment, u32 game_id, char* api_key);
  //void MODIO_DLL init(int game_id, char* api_key, char* root_path);
  void MODIO_DLL modioShutdown();
  void MODIO_DLL modioSetDebugLevel(u32 debug_level);
  void MODIO_DLL modioProcess();
  void MODIO_DLL modioSleep(u32 milliseconds);

  //Events
  void MODIO_DLL modioSetEventListener(void (*callback)(ModioResponse response, ModioEvent* events_array, u32 events_array_size));
  void MODIO_DLL modioGetEvents(void* object, u32 mod_id, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size));
  void MODIO_DLL modioGetAllEvents(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size));

  //Authentication methods
  void MODIO_DLL modioEmailRequest(void* object, char* email, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioEmailExchange(void* object, char* security_code, void (*callback)(void* object, ModioResponse response));
  bool MODIO_DLL modioIsLoggedIn();
  void MODIO_DLL modioLogout();

  //Image Methods
  void MODIO_DLL modioDownloadImage(void* object, char* image_url, char* path, void (*callback)(void* object, ModioResponse response));

  //Modfile Methods
  void MODIO_DLL modioGetModfile(void* object, u32 mod_id, u32 modfile_id, void (*callback)(void* object, ModioResponse response, ModioModfile modfile));
  void MODIO_DLL modioGetModfiles(void* object, u32 mod_id, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioModfile modfiles[], u32 modfiles_size));
  void MODIO_DLL modioAddModfile(u32 mod_id, ModioModfileCreator modfile_creator);
  void MODIO_DLL modioEditModfile(void* object, u32 mod_id, u32 modfile_id, ModioModfileEditor modfile_handler, void (*callback)(void* object, ModioResponse response, ModioModfile modfile));

  //Mods Methods
  void MODIO_DLL modioGetMod(void* object, u32 mod_id, void (*callback)(void* object, ModioResponse response, ModioMod mod));
  void MODIO_DLL modioGetMods(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size));
  void MODIO_DLL modioAddMod(void* object, ModioModCreator mod_handler, void (*callback)(void* object, ModioResponse response, ModioMod mod));
  void MODIO_DLL modioEditMod(void* object, u32 mod_id, ModioModEditor mod_handler, void (*callback)(void* object, ModioResponse response, ModioMod mod));
  void MODIO_DLL modioDeleteMod(void* object, u32 mod_id, void (*callback)(void* object, ModioResponse response));

  //Media Methods
  void MODIO_DLL modioAddModLogo(void* object, u32 mod_id, char* logo_path, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioAddModImages(void* object, u32 mod_id, char** image_paths_array, u32 image_paths_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioAddModYoutubeLinks(void* object, u32 mod_id, char** youtube_links_array, u32 youtube_links_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioAddModSketchfabLinks(void* object, u32 mod_id, char** sketchfab_links_array, u32 sketchfab_links_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioDeleteModImages(void* object, u32 mod_id, char** image_paths_array, u32 image_paths_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioDeleteModYoutubeLinks(void* object, u32 mod_id, char** youtube_links_array, u32 youtube_links_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioDeleteModSketchfabLinks(void* object, u32 mod_id, char** sketchfab_links_array, u32 sketchfab_links_array_size, void (*callback)(void* object, ModioResponse response));

  //Ratings Methods
  void MODIO_DLL modioAddModRating(void* object, u32 mod_id, bool vote_up, void (*callback)(void* object, ModioResponse response));

  //Subscription Methods
  void MODIO_DLL modioSubscribeToMod(void* object, u32 mod_id, void (*callback)(void* object, ModioResponse response, ModioMod mod));
  void MODIO_DLL modioUnsubscribeFromMod(void* object, u32 mod_id, void (*callback)(void* object, ModioResponse response));

  //Tags Methods
  void MODIO_DLL modioGetTags(void* object, u32 mod_id, void (*callback)(void* object, ModioResponse response, ModioTag* tags_array, u32 tags_array_size));
  void MODIO_DLL modioAddTags(void* object, u32 mod_id, char** tags_array, u32 tags_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioDeleteTags(void* object, u32 mod_id, char** tags_array, u32 tags_array_size, void (*callback)(void* object, ModioResponse response));

  //Metadata KVP Methods
  void MODIO_DLL modioGetMetadataKVP(void* object, u32 mod_id, void (*callback)(void* object, ModioResponse response, ModioMetadataKVP* metadata_kvp_array, u32 metadata_kvp_array_size));
  void MODIO_DLL modioAddMetadataKVP(void* object, u32 mod_id, char** metadata_kvp_array, u32 metadata_kvp_array_size, void (*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioDeleteMetadataKVP(void* object, u32 mod_id, char** metadata_kvp_array, u32 metadata_kvp_array_size, void (*callback)(void* object, ModioResponse response));

  //Filter Handler Methods
  void MODIO_DLL modioInitFilter(ModioFilterCreator* filter);
  void MODIO_DLL modioSetFilterSort(ModioFilterCreator* filter, char* field, bool ascending);
  void MODIO_DLL modioSetFilterLimit(ModioFilterCreator* filter, u32 limit);
  void MODIO_DLL modioSetFilterOffset(ModioFilterCreator* filter, u32 offset);
  void MODIO_DLL modioSetFilterFullTextSearch(ModioFilterCreator* filter, char* text);
  void MODIO_DLL modioSetFilterCacheMaxAgeSeconds(ModioFilterCreator* filter, u32 max_age_seconds);
  void MODIO_DLL modioAddFilterFieldValue(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterLikeField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterNotLikeField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterInField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterNotInField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterMinField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterMaxField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterSmallerThanField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterGreaterThanField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioAddFilterNotEqualField(ModioFilterCreator* filter, char* field, char* value);
  void MODIO_DLL modioFreeFilter(ModioFilterCreator* filter);

  //Modfile Creator Methods
  void MODIO_DLL modioInitModfileCreator(ModioModfileCreator* modfile_creator);
  void MODIO_DLL modioSetModfileCreatorPath(ModioModfileCreator* modfile_creator, char* path);
  void MODIO_DLL modioSetModfileCreatorVersion(ModioModfileCreator* modfile_creator, char* version);
  void MODIO_DLL modioSetModfileCreatorChangelog(ModioModfileCreator* modfile_creator, char* changelog);
  void MODIO_DLL modioSetModfileCreatorActive(ModioModfileCreator* modfile_creator, bool active);
  void MODIO_DLL modioSetModfileCreatorFilehash(ModioModfileCreator* modfile_creator, char* filehash);
  void MODIO_DLL modioFreeModfileCreator(ModioModfileCreator* modfile_creator);

  //Modfile Editor Methods
  void MODIO_DLL modioInitModfileEditor(ModioModfileEditor* modfile_creator);
  void MODIO_DLL modioSetModfileEditorVersion(ModioModfileEditor* modfile_creator, char* version);
  void MODIO_DLL modioSetModfileEditorChangelog(ModioModfileEditor* modfile_creator, char* changelog);
  void MODIO_DLL modioSetModfileEditorActive(ModioModfileEditor* modfile_creator, bool active);
  void MODIO_DLL modioFreeModfileEditor(ModioModfileEditor* modfile_creator);

  //Mod Creator Methods
  void MODIO_DLL modioInitModCreator(ModioModCreator* mod_creator);
  void MODIO_DLL modioSetModCreatorVisible(ModioModCreator* mod_creator, u32 visible);
  void MODIO_DLL modioSetModCreatorMaturityOption(ModioModCreator* mod_creator, u32 maturity_option);
  void MODIO_DLL modioSetModCreatorLogoPath(ModioModCreator* mod_creator, char* logo_path);
  void MODIO_DLL modioSetModCreatorName(ModioModCreator* mod_creator, char* name);
  void MODIO_DLL modioSetModCreatorNameid(ModioModCreator* mod_creator, char* name_id);
  void MODIO_DLL modioSetModCreatorSummary(ModioModCreator* mod_creator, char* summary);
  void MODIO_DLL modioSetModCreatorDescription(ModioModCreator* mod_creator, char* description);
  void MODIO_DLL modioSetModCreatorHomepageURL(ModioModCreator* mod_creator, char* homepage_url);
  void MODIO_DLL modioSetModCreatorMetadataBlob(ModioModCreator* mod_creator, char* metadata_blob);
  void MODIO_DLL modioAddModCreatorTag(ModioModCreator* mod_creator, char* tag);
  void MODIO_DLL modioFreeModCreator(ModioModCreator* mod_creator);

  //Mod Editor Methods
  void MODIO_DLL modioInitModEditor(ModioModEditor* update_mod_handler);
  void MODIO_DLL modioSetModEditorVisible(ModioModEditor* update_mod_handler, u32 visible);
  void MODIO_DLL modioSetModEditorStatus(ModioModEditor* update_mod_handler, u32 status);
  void MODIO_DLL modioSetModEditorMaturityOption(ModioModEditor* mod_editor, u32 maturity_option);
  void MODIO_DLL modioSetModEditorName(ModioModEditor* update_mod_handler, char* name);
  void MODIO_DLL modioSetModEditorNameid(ModioModEditor* update_mod_handler, char* name_id);
  void MODIO_DLL modioSetModEditorSummary(ModioModEditor* update_mod_handler, char* summary);
  void MODIO_DLL modioSetModEditorDescription(ModioModEditor* update_mod_handler, char* description);
  void MODIO_DLL modioSetModEditorHomepageURL(ModioModEditor* update_mod_handler, char* homepage_url);
  void MODIO_DLL modioSetModEditorModfile(ModioModEditor* update_mod_handler, u32 modfile);
  void MODIO_DLL modioSetModEditorMetadataBlob(ModioModEditor* update_mod_handler, char* metadata_blob);
  void MODIO_DLL modioFreeModEditor(ModioModEditor* update_mod_handler);

  //Me Methods
  void MODIO_DLL modioGetAuthenticatedUser(void* object, void (*callback)(void* object, ModioResponse response, ModioUser user));
  void MODIO_DLL modioGetUserSubscriptions(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size));
  void MODIO_DLL modioGetUserEvents(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size));
  void MODIO_DLL modioGetUserGames(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioGame games[], u32 games_size));
  void MODIO_DLL modioGetUserMods(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size));
  void MODIO_DLL modioGetUserModfiles(void* object, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioModfile modfiles[], u32 modfiles_size));

  //Settings Methods
  void MODIO_DLL modioInitConfig();
  u32 MODIO_DLL modioGetAutomaticUpdatesConfig();
  u32 MODIO_DLL modioGetAllowBackgroundDownloadsConfig();
  void MODIO_DLL modioSetAutomaticUpdatesConfig(u32 option);
  void MODIO_DLL modioSetAllowBackgroundDownloadsConfig(u32 option);

  //Downloads Methods
  void MODIO_DLL modioInstallMod(u32 mod_id);
  bool MODIO_DLL modioUninstallMod(u32 mod_id);
  void MODIO_DLL modioPauseDownloads();
  void MODIO_DLL modioResumeDownloads();
  void MODIO_DLL modioPrioritizeModDownload(u32 mod_id);
  void MODIO_DLL modioSetDownloadListener(void (*callback)(u32 response_code, u32 mod_id));  
  void MODIO_DLL modioSetUploadListener(void (*callback)(u32 response_code, u32 mod_id));  
  u32 MODIO_DLL modioGetModDownloadQueueCount();
  void MODIO_DLL modioGetModDownloadQueue(ModioQueuedModDownload* download_queue);
  u32 MODIO_DLL modioGetModfileUploadQueueCount();
  void MODIO_DLL modioGetModfileUploadQueue(ModioQueuedModfileUpload* upload_queue);
  u32 MODIO_DLL modioGetInstalledModsCount();
  void MODIO_DLL modioGetInstalledMods(ModioInstalledMod* installed_mods);
  u32 MODIO_DLL modioGetModState(u32 mod_id);

  //Dependencies Methods
  void MODIO_DLL modioGetAllModDependencies(void* object, u32 mod_id, void(*callback)(void* object, ModioResponse response, ModioDependency* dependencies_array, u32 dependencies_array_size));
  void MODIO_DLL modioAddModDependencies(void* object, u32 mod_id, u32* dependencies_array, u32 dependencies_array_size, void(*callback)(void* object, ModioResponse response));
  void MODIO_DLL modioDeleteModDependencies(void* object, u32 mod_id, u32* dependencies_array, u32 dependencies_array_size, void(*callback)(void* object, ModioResponse response));

  //Comment Methods
  void MODIO_DLL modioGetAllModComments(void* object, u32 mod_id, ModioFilterCreator filter, void (*callback)(void* object, ModioResponse response, ModioComment comments[], u32 comments_size));
  void MODIO_DLL modioDeleteModComment(void* object, u32 mod_id, u32 comment_id, void(*callback)(void* object, ModioResponse response));

  //Reports Methods
  void MODIO_DLL modioSubmitReport(void* object, char* resource, u32 id, u32 type, char* name, char* summary, void(*callback)(void* object, ModioResponse response));
}

#endif
