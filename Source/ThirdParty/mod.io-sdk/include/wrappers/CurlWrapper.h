#ifndef MODIO_CURL_WRAPPER_H
#define MODIO_CURL_WRAPPER_H

#include <stdio.h>                                               // for FILE
#include <functional>                                            // for func...
#include <map>                                                   // for map
#include <string>                                                // for string
#include <vector>                                                // for vector
#include "c++/schemas/../../dependencies/nlohmann/json.hpp"      // for json
#include "c++/schemas/../creators/../../c/creators/../ModioC.h"  // for u32
namespace modio { class QueuedModDownload; }
namespace modio { class QueuedModfileUpload; }


#ifdef MODIO_WINDOWS_DETECTED
#  pragma comment(lib, "ws2_32.lib")
#endif

namespace modio
{
namespace curlwrapper
{
//General use
void initCurl();
void shutdownCurl();
u32 getCallNumber();
void process();

//HTTP methods
void get(u32 call_number, std::string url, std::vector<std::string> headers, std::function<void(u32 call_number, u32 response_code, nlohmann::json response_json)> callback);
void post(u32 call_number, std::string url, std::vector<std::string> headers, std::map<std::string, std::string> data, std::function<void(u32 call_number, u32 response_code, nlohmann::json response_json)> callback);
void put(u32 call_number, std::string url, std::vector<std::string> headers, std::multimap<std::string, std::string> curlform_copycontents, std::function<void(u32 call_number, u32 response_code, nlohmann::json response_json)> callback);
void postForm(u32 call_number, std::string url, std::vector<std::string> headers, std::multimap<std::string, std::string> curlform_copycontents, std::map<std::string, std::string> curlform_files, std::function<void(u32 call_number, u32 response_code, nlohmann::json response_json)> callback);
void deleteCall(u32 call_number, std::string url, std::vector<std::string> headers, std::map<std::string, std::string> data, std::function<void(u32 call_number, u32 response_code, nlohmann::json response_json)> callback);

//Downloads methods
void pauseModDownloads();
void resumeModDownloads();
void download(u32 call_number, std::vector<std::string> headers, std::string url, std::string path, FILE *file, std::function<void(u32 call_number, u32 response_code)> callback);
void downloadMod(QueuedModDownload *queued_mod_download);
void queueModDownload(ModioMod& modio_mod);
void uploadModfile(QueuedModfileUpload *queued_modfile_upload);
void queueModfileUpload(u32 mod_id, ModioModfileCreator *modio_modfile_creator);
void removeDownloadedMod(u32 mod_id);

}
}

#endif
