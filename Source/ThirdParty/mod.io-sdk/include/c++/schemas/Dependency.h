#ifndef MODIO_DEPENDENCY_H
#define MODIO_DEPENDENCY_H

#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioDependency
#include "User.h"

namespace modio
{
class Dependency
{
public:
	u32 mod_id;
	u32 date_added;

	void initialize(ModioDependency modio_dependency);
};

extern nlohmann::json toJson(Dependency &dependency);
} // namespace modio

#endif
