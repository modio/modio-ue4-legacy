#ifndef MODIO_DEPENDENCIES_CALLBACKS_H
#define MODIO_DEPENDENCIES_CALLBACKS_H

#include "../../../Globals.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioDependency.h"

struct GetAllModDependenciesParams
{
	void* object;
	void(*callback)(void* object, ModioResponse response, ModioDependency* dependencies_array, u32 dependencies_array_size);
};

struct AddModDependienciesParams
{
	void* object;
	void(*callback)(void* object, ModioResponse response);
};

struct DeleteModDependenciesParams
{
	void* object;
	void(*callback)(void* object, ModioResponse response);
};

extern std::map< u32, GetAllModDependenciesParams* > get_all_mod_dependencies_callbacks;
extern std::map< u32, AddModDependienciesParams* > add_mod_dependencies_callbacks;
extern std::map< u32, DeleteModDependenciesParams* > delete_mod_dependencies_callbacks;

void modioOnGetAllModDependencies(u32 call_number, u32 response_code, json response_json);
void modioOnAddModDependencies(u32 call_number, u32 response_code, json response_json);
void modioOnDeleteModDependencies(u32 call_number, u32 response_code, json response_json);

#endif
