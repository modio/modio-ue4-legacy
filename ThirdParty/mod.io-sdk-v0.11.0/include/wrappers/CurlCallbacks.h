#ifndef MODIO_CURL_CALLBACKS_H
#define MODIO_CURL_CALLBACKS_H

#include "CurlUtility.h"
#include "CurlWrapper.h"
#include "CurlProgressFunctions.h"
#include "CurlWriteFunctions.h"

namespace modio
{
namespace curlwrapper
{

void onJsonRequestFinished(CURL* curl);
void onDownloadFinished(CURL* curl);
void onModDownloadFinished(CURL* curl);
void onModfileUploadFinished(CURL* curl);

}
}

#endif