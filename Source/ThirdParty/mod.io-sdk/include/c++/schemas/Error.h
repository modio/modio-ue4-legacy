#ifndef MODIO_ERROR_H
#define MODIO_ERROR_H

#include <string>                                 // for string
#include <vector>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioError

namespace modio
{
class Error
{
public:
  u32 code;
  u32 error_ref;
  std::string message;
  std::vector<std::string> errors;

  void initialize(ModioError error);
};

extern nlohmann::json toJson(Error &error);
} // namespace modio

#endif
