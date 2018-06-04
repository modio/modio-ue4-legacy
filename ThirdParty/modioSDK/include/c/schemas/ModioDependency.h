#ifndef MODIO_MODIODEPENDENCY_H
#define MODIO_MODIODEPENDENCY_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitDependency(ModioDependency* dependency, json dependency_json);
  void modioFreeDependency(ModioDependency* dependency);
}

#endif
