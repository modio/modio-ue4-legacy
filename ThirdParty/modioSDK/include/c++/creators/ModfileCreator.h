#ifndef MODIO_MODFILE_CREATOR_H
#define MODIO_MODFILE_CREATOR_H

#include "../../c/creators/ModioModfileCreator.h"

namespace modio
{
  class MODIO_DLL ModfileCreator
  {
    ModioModfileCreator* modfile_creator;
  public:
    ModfileCreator();
    void initializeFromModioModfileCreator(ModioModfileCreator* modfile_creator);    
    void setPath(const std::string& path);
    void setVersion(const std::string& version);
    void setChangelog(const std::string& changelog);
    void setActive(bool active);
    void setFilehash(const std::string& filehash);
    ModioModfileCreator* getModioModfileCreator();
    ~ModfileCreator();
    json toJson();    
  };
}

#endif
