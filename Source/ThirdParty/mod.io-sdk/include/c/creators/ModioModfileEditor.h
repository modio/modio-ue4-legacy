#ifndef MODIO_MODIO_MODFILE_EDITOR_H
#define MODIO_MODIO_MODFILE_EDITOR_H

#include <map>          // for multimap
#include <string>       // for string
#include "../ModioC.h"  // for ModioModfileEditor

namespace modio
{
  std::multimap<std::string, std::string> convertModfileEditorToMultimap(ModioModfileEditor* modfile_editor);
}

#endif
