#ifndef MODIO_MODIODEPENDENCY_H
#define MODIO_MODIODEPENDENCY_H

#include "../ModioC.h"                     // for ModioDependency
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitDependency(ModioDependency* dependency, nlohmann::json dependency_json);
  void modioFreeDependency(ModioDependency* dependency);
}

#endif
