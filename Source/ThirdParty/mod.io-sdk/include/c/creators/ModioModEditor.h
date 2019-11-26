#ifndef MODIO_MODIO_MOD_EDITOR_H
#define MODIO_MODIO_MOD_EDITOR_H

#include <map>                                // for multimap
#include <string>                             // for string
#include "../ModioC.h"  // for ModioModEditor


namespace modio
{
  std::multimap<std::string, std::string> getModEditorCurlFormCopyContentsParams(ModioModEditor* mod_editor);
}

#endif
