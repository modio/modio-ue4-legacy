// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioResponse.h"

void InitializeResponse(FModioResponse &Response, const ModioResponse &modio_response)
{
  Response.Code = modio_response.code;
  Response.ResultCount = modio_response.result_count;
  Response.ResultLimit = modio_response.result_limit;
  Response.ResultOffset = modio_response.result_offset;
  Response.ResultTotal = modio_response.result_total;
  Response.ResultCached = modio_response.result_cached;
  InitializeError(Response.Error, modio_response.error);
}