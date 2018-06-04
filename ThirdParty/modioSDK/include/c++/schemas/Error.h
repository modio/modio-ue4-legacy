#ifndef MODIO_ERROR_H
#define MODIO_ERROR_H

#include "../../c/schemas/ModioError.h"
#include "../../Globals.h"

namespace modio
{
  class Error
  {
  public:
    u32 code;
    std::string message;
    std::vector<std::string> errors;

    void initialize(ModioError error);
    json toJson();
  };
}

#endif
