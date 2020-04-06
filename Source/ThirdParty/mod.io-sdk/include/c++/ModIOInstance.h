#ifndef MODIO_INSTANCE_H
#define MODIO_INSTANCE_H

#include <functional>              // for function
#include <list>                    // for list
#include <map>                     // for map
#include <string>                  // for string
#include <vector>                  // for vector
#include "c/ModioC.h"              // for u32, MODIO_DLL
#include "schemas/InstalledMod.h"  // for InstalledMod
#include "schemas/User.h"          // for User
namespace modio { class Comment; }
namespace modio { class Dependency; }
namespace modio { class FilterCreator; }
namespace modio { class Game; }
namespace modio { class MetadataKVP; }
namespace modio { class Mod; }
namespace modio { class ModCreator; }
namespace modio { class ModEditor; }
namespace modio { class ModEvent; }
namespace modio { class Modfile; }
namespace modio { class ModfileCreator; }
namespace modio { class ModfileEditor; }
namespace modio { class QueuedModDownload; }
namespace modio { class QueuedModfileUpload; }
namespace modio { class Rating; }
namespace modio { class Response; }
namespace modio { class Stats; }
namespace modio { class Tag; }
namespace modio { class UserEvent; }

namespace modio
{
class MODIO_DLL Instance
{
  u32 current_call_id;

  Instance(const Instance&) = delete;
  Instance& operator=(const Instance&) = delete;
public:
  Instance(u32 environment, u32 game_id, const std::string &api_key);
  Instance(u32 environment, u32 game_id, bool retrieve_mods_from_other_games, bool polling_enabled, const std::string &api_key, const std::string &root_path);
  ~Instance();

  //General Methods
  void process();
  void pollEvents();
  void setDebugLevel(u32 debug_level);
  void setModEventsPollInterval(u32 interval_in_seconds);
  void setUserEventsPollInterval(u32 interval_in_seconds);
  void sleep(u32 milliseconds);
  void compressFiles(std::string root_directory, std::vector<std::string> filenames, std::string zip_path);

  //Events
  void getEvents(u32 mod_id, modio::FilterCreator &filter, const std::function<void(const modio::Response &, const std::vector<modio::ModEvent> &events)> &callback);
  void getAllEvents(modio::FilterCreator &filter, const std::function<void(const modio::Response &, const std::vector<modio::ModEvent> &events)> &callback);
  void setEventListener(const std::function<void(const modio::Response &, const std::vector<modio::ModEvent> &events)> &callback);

  //Authentication Methods
  bool isLoggedIn() const;
  void logout() const;
  void emailRequest(const std::string &email, const std::function<void(const modio::Response &)> &callback);
  void emailExchange(const std::string &security_code, const std::function<void(const modio::Response &)> &callback);
  void authenticateViaToken(const std::string &access_token);
  modio::User getCurrentUser();

  //External Authentication Methods
  void galaxyAuth(const std::string &appdata, const std::function<void(const modio::Response &)> &callback);
  void oculusAuth(const std::string &nonce, const std::string &oculus_user_id, const std::string &access_token, const std::string &email, const std::string &device, u32 date_expires, const std::function<void(const modio::Response &)> &callback);
  void steamAuth(const unsigned char* rgubTicket, u32 cubTicket, const std::function<void(const modio::Response &)> &callback);
  void steamAuthEncoded(const std::string &base64_token, const std::function<void(const modio::Response &)> &callback);
  void linkExternalAccount(u32 service, const std::string &service_id, const std::string &email, const std::function<void(const modio::Response &)> &callback);

  //Media Methods
  void downloadImage(const std::string &image_url, const std::string &path, const std::function<void(const modio::Response &)> &callback);

  //Mod Methods
  void addMod(modio::ModCreator &mod_handler, const std::function<void(const modio::Response &response, const modio::Mod &mod)> &callback);
  void getMod(u32 mod_id, const std::function<void(const modio::Response &response, const modio::Mod &mod)> &callback);
  void getAllMods(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Mod> &mods)> &callback);
  void editMod(u32 mod_id, modio::ModEditor &mod_handler, const std::function<void(const modio::Response &response, const modio::Mod &mod)> &callback);
  void deleteMod(u32 mod_id, const std::function<void(const modio::Response &response)> &callback);

  //Media Methods
  void addModLogo(u32 mod_id, std::string logo_path, const std::function<void(const modio::Response &response)> &callback);
  void addModImages(u32 mod_id, std::vector<std::string> image_paths, const std::function<void(const modio::Response &response)> &callback);
  void addModYoutubeLinks(u32 mod_id, std::vector<std::string> youtube_links, const std::function<void(const modio::Response &response)> &callback);
  void addModSketchfabLinks(u32 mod_id, std::vector<std::string> sketchfab_links, const std::function<void(const modio::Response &response)> &callback);
  void deleteModImages(u32 mod_id, std::vector<std::string> image_paths, const std::function<void(const modio::Response &response)> &callback);
  void deleteModYoutubeLinks(u32 mod_id, std::vector<std::string> youtube_links, const std::function<void(const modio::Response &response)> &callback);
  void deleteModSketchfabLinks(u32 mod_id, std::vector<std::string> sketchfab_links, const std::function<void(const modio::Response &response)> &callback);

  //Modfile Methods
  void getModfile(u32 mod_id, u32 modfile_id, const std::function<void(const modio::Response &response, const modio::Modfile &modfile)> &callback);
  void getAllModfiles(u32 mod_id, modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Modfile> &modfiles)> &callback);
  void addModfile(u32 mod_id, modio::ModfileCreator &modfile_handler);
  void editModfile(u32 mod_id, u32 modfile_id, modio::ModfileEditor &modfile_handler, const std::function<void(const modio::Response &response, const modio::Modfile &modfile)> &callback);
  void deleteModfile(u32 mod_id, u32 modfile_id, const std::function<void(const modio::Response &response)> &callback);

  //Tag Methods
  void getModTags(u32 mod_id, const std::function<void(const modio::Response &response, std::vector<modio::Tag> tags)> &callback);
  void addModTags(u32 mod_id, std::vector<std::string> tags, const std::function<void(const modio::Response &response)> &callback);
  void deleteModTags(u32 mod_id, std::vector<std::string> tags, const std::function<void(const modio::Response &response)> &callback);

  //Metadata KVP methods
  void getAllMetadataKVP(u32 mod_id, const std::function<void(const modio::Response &response, std::vector<modio::MetadataKVP> metadata_kvp)> &callback);
  void addMetadataKVP(u32 mod_id, std::map<std::string, std::string> metadata_kvp, const std::function<void(const modio::Response &response)> &callback);
  void deleteMetadataKVP(u32 mod_id, std::map<std::string, std::string> metadata_kvp, const std::function<void(const modio::Response &response)> &callback);

  //Ratings Methods
  void addModRating(u32 mod_id, bool vote_up, const std::function<void(const modio::Response &response)> &callback);
  u32 getCurrentUserModRating(u32 mod_id);

  //Subscription Methods
  void subscribeToMod(u32 mod_id, const std::function<void(const modio::Response &response, const modio::Mod &mod)> &callback);
  void unsubscribeFromMod(u32 mod_id, const std::function<void(const modio::Response &response)> &callback);
  bool isCurrentUserSubscribed(u32 mod_id);
  const std::vector<u32> getCurrentUserSubscriptions();

  //Me Methods
  void getAuthenticatedUser(const std::function<void(const modio::Response &response, const modio::User &user)> &callback);
  void getUserSubscriptions(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Mod> &mods)> &callback);
  void getUserEvents(modio::FilterCreator &filter, const std::function<void(const modio::Response &, const std::vector<modio::UserEvent> &events)> &callback);
  void getUserGames(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Game> &games)> &callback);
  void getUserMods(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Mod> &mods)> &callback);
  void getUserModfiles(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Modfile> &modfiles)> &callback);
  void getUserRatings(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Rating> &ratings)> &callback);

  //Downloads Methods
  void downloadMod(u32 mod_id);
  void installDownloadedMods();
  void uninstallMod(u32 mod_id);
  void pauseDownloads();
  void resumeDownloads();
  void prioritizeModDownload(u32 mod_id);  
  void setDownloadListener(const std::function<void(u32 response_code, u32 mod_id)> &callback);
  void setUploadListener(const std::function<void(u32 response_code, u32 mod_id)> &callback);
  void downloadModfilesById(const std::vector<u32> mod_ids, const std::function<void(const modio::Response &, const bool mods_are_updated)> &callback);
  const std::list<QueuedModDownload *> getModDownloadQueue();
  const std::list<QueuedModfileUpload *> getModfileUploadQueue();
  const modio::InstalledMod getInstalledMod(u32 mod_id);
  const std::vector<modio::InstalledMod> getAllInstalledMods();
  const std::vector<u32> getAllDownloadedMods();
  u32 getModState(u32 mod_id);

  //Dependencies Methods
  void getAllModDependencies(u32 mod_id, const std::function<void(const modio::Response &response, const std::vector<modio::Dependency> &mods)> &callback);
  void addModDependencies(u32 mod_id, std::vector<u32> dependencies, const std::function<void(const modio::Response &response)> &callback);
  void deleteModDependencies(u32 mod_id, std::vector<u32> dependencies, const std::function<void(const modio::Response &response)> &callback);

  //Comments Methods
  void getAllModComments(u32 mod_id, modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Comment> &comments)> &callback);
  void getModComment(u32 mod_id, u32 comment_id, const std::function<void(const modio::Response &response, const modio::Comment &comment)> &callback);
  void deleteModComment(u32 mod_id, u32 comment_id, const std::function<void(const modio::Response &response)> &callback);

  //Reports Methods
  void submitReport(std::string resource, u32 id, u32 type, std::string name, std::string summary, const std::function<void(const modio::Response &response)> &callback);

  //Stats Methods
  void getModStats(u32 mod_id, const std::function<void(const modio::Response &response, const modio::Stats &stats)> &callback);
  void getAllModStats(modio::FilterCreator &filter, const std::function<void(const modio::Response &response, const std::vector<modio::Stats> &mods_stats)> &callback);
};
}

#endif
