#ifndef MODIO_RESPONSE_H
#define MODIO_RESPONSE_H

#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioResponse
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
