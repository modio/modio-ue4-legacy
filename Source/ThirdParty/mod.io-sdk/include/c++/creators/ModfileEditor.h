#ifndef MODIO_MODFILE_EDITOR_H
#define MODIO_MODFILE_EDITOR_H

#include "../../c/creators/ModioModfileEditor.h"

namespace modio
{
  class MODIO_DLL ModfileEditor
  {
    ModioModfileEditor modfile_editor;
    ModfileEditor(const ModfileEditor&) = delete;
    ModfileEditor& operator=(const ModfileEditor&) = delete;
  public:
    ModfileEditor();
    void setVersion(const std::string& version);
    void setChangelog(const std::string& changelog);
    void setMetadataBlob(const std::string& metadata_blob);
    void setActive(bool active);
    ModioModfileEditor* getModioModfileEditor();
    ~ModfileEditor();
  };
}

#endif
