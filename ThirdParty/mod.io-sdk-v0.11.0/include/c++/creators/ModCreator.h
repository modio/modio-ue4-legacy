#ifndef MODIO_MOD_CREATOR_H
#define MODIO_MOD_CREATOR_H

#include "../../c/creators/ModioModCreator.h"

namespace modio
{
  class MODIO_DLL ModCreator
  {
    ModioModCreator* mod_creator;
  public:
    ModCreator();
    void setVisible(u32 visible);
    void setMaturityOption(u32 maturity_option);
    void setLogoPath(const std::string& path);
    void setName(const std::string& name);
    void setNameid(const std::string& name_id);
    void setSummary(const std::string& summary);
    void setDescription(const std::string& description);
    void setHomepageURL(const std::string& homepage_url);
    void setMetadataBlob(const std::string& metadata_blob);
    void addTag(const std::string& tag);
    ModioModCreator* getModioModCreator();
    ~ModCreator();
  };
}

#endif
