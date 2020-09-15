// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioResponse.h"

void InitializeResponse( FModioResponse &Out_Response, const ModioResponse &ModioResponse )
{
  Out_Response.Code = ModioResponse.code;
  Out_Response.ResultCount = ModioResponse.result_count;
  Out_Response.ResultLimit = ModioResponse.result_limit;
  Out_Response.ResultOffset = ModioResponse.result_offset;
  Out_Response.ResultTotal = ModioResponse.result_total;
  Out_Response.ResultCached = ModioResponse.result_cached;
  InitializeError( Out_Response.Error, ModioResponse.error );
}