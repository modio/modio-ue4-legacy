#ifndef MODIO_MODIODEPENDENCY_H
#define MODIO_MODIODEPENDENCY_H

#include "../ModioC.h"                     // for ModioDependency
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Dependency.h"

extern "C"
{
  void modioInitDependency(ModioDependency* dependency, nlohmann::json dependency_json);
  void modioInitDependencyCpp(ModioDependency* modio_dependency, modio::Dependency* dependency);
  void modioFreeDependency(ModioDependency* dependency);
}

#endif
