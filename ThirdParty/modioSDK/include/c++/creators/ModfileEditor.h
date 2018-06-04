#ifndef MODIO_MODFILE_EDITOR_H
#define MODIO_MODFILE_EDITOR_H

#include "../../c/creators/ModioModfileEditor.h"

namespace modio
{
  class MODIO_DLL ModfileEditor
  {
    ModioModfileEditor* modfile_editor;
  public:
    ModfileEditor();
    void setVersion(const std::string& version);
    void setChangelog(const std::string& changelog);
    void setActive(bool active);
    ModioModfileEditor* getModioModfileEditor();
    ~ModfileEditor();
  };
}

#endif
