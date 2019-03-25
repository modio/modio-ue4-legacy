#ifndef MODIO_CURL_WRITE_FUNCTIONS_H
#define MODIO_CURL_WRITE_FUNCTIONS_H

#include "CurlUtility.h"

namespace modio
{
namespace curlwrapper
{
size_t onGetJsonData(char *ptr, size_t size, size_t nmemb, void *userdata);
size_t onGetUploadData(char *ptr, size_t size, size_t nmemb, void *userdata);
size_t onGetFileData(void *ptr, size_t size, size_t nmemb, void *stream);
size_t headerCallback(char *ptr, size_t size, size_t nitems, void *userdata);
}
}

#endif