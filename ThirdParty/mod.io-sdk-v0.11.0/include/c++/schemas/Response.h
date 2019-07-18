#ifndef MODIO_RESPONSE_H
#define MODIO_RESPONSE_H

#include "../../Globals.h"
#include "../../c/schemas/ModioResponse.h"
#include "Error.h"

namespace modio
{
class Response
{
public:
  u32 code;
  u32 result_count;
  u32 result_limit;
  i32 result_offset;
  u32 result_total;
  bool result_cached;
  modio::Error error;

  void initialize(ModioResponse response);
};

extern nlohmann::json toJson(Response &response);
} // namespace modio

#endif
