#ifndef MODIO_CURL_UTILITY_H
#define MODIO_CURL_UTILITY_H

#include <stdio.h>
#include <iostream>
#include <map>
#include <list>

#include "../dependencies/json/json.hpp"
#include "../dependencies/curl/curl.h"
#include "../Utility.h"
#include "../Globals.h"
#include "MinizipWrapper.h"
#include "CurlProgressFunctions.h"
#include "CurlWriteFunctions.h"
#include "../c++/schemas/QueuedModDownload.h"
#include "../c++/schemas/QueuedModfileUpload.h"
#include "../c/schemas/ModioQueuedModDownload.h"
#include "../c/schemas/ModioQueuedModfileUpload.h"
#include "../ModUtility.h"

#define SKIP_PEER_VERIFICATION
#define SKIP_HOSTNAME_VERIFICATION

using json = nlohmann::json;

namespace modio
{
namespace curlwrapper
{

class JsonResponseHandler
{
public:
  u32 call_number;
  std::string response;
  std::function<void(u32 call_number, u32 response_code, json response_json)> callback;
  JsonResponseHandler(u32 call_number, std::function<void(u32 call_number, u32 response_code, json response_json)> callback);
};

class OngoingDownload
{
public:
  u32 call_number;
  std::string url;
  std::function<void(u32 call_number, u32 response_code)> callback;
  OngoingDownload(u32 call_number, std::string url, std::function<void(u32 call_number, u32 response_code)> callback);
};

struct CurrentDownloadHandle
{
  CURL *curl;
  std::string path;
  bool pause_flag;
};

extern std::list<QueuedModDownload *> mod_download_queue;
extern std::list<QueuedModfileUpload *> modfile_upload_queue;
extern FILE *current_mod_download_file;
extern CURL *current_mod_download_curl_handle;
extern QueuedModDownload *current_queued_mod_download;
extern CURL *current_modfile_upload_curl_handle;
extern QueuedModfileUpload *current_queued_modfile_upload;

extern CURLM *curl_multi_handle;

extern std::map<CURL *, JsonResponseHandler *> ongoing_calls;
extern std::map<CURL *, OngoingDownload *> ongoing_downloads;

extern CurrentDownloadHandle *current_download_handle;

extern u32 call_count;
extern u32 ongoing_call;

std::list<QueuedModDownload *> getModDownloadQueue();
std::list<QueuedModfileUpload *> getModfileUploadQueue();

void updateModDownloadQueue();
void updateModDownloadQueueFile();
void updateModUploadQueueFile();
void prioritizeModDownload(u32 mod_id);

void setHeaders(std::vector<std::string> headers, CURL *curl);
void setVerifies(CURL *curl);
void setJsonResponseWrite(CURL *curl);
}
}

#endif
