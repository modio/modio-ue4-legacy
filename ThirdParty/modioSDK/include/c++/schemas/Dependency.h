#ifndef MODIO_DEPENDENCY_H
#define MODIO_DEPENDENCY_H

#include "../../c/schemas/ModioDependency.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
	class Dependency
	{
	public:
		u32 mod_id;
		u32 date_added;

		void initialize(ModioDependency modio_dependency);
		json toJson();
	};
}

#endif
