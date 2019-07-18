#ifndef MODIO_MODIO_MODFILE_EDITOR_H
#define MODIO_MODIO_MODFILE_EDITOR_H

#include "../../Globals.h"
#include "../ModioC.h"

namespace modio
{
  std::multimap<std::string, std::string> convertModfileEditorToMultimap(ModioModfileEditor* modfile_editor);
}

#endif
