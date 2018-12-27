#ifndef MODIO_MODIODEPENDENCY_H
#define MODIO_MODIODEPENDENCY_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitDependency(ModioDependency* dependency, nlohmann::json dependency_json);
  void modioFreeDependency(ModioDependency* dependency);
}

#endif
