#ifndef MODIO_MODIOTERMS_H
#define MODIO_MODIOTERMS_H

#include "../ModioC.h"                     // for ModioMod
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Terms.h"  // for modioInitMod ...

extern "C"
{
  void modioInitTerms(ModioTerms* terms, const nlohmann::json& terms_json);
  void modioInitTermsCpp(ModioTerms* modio_terms, const modio::Terms* terms);
  void modioFreeTerms(ModioTerms* terms);

  void modioInitButton(ModioButton* button, const nlohmann::json& button_json);
  void modioInitButtonCpp(ModioButton* modio_button, const modio::Button* button);
  void modioFreeButton(ModioButton* button);

  void modioInitLink(ModioLink* link, const nlohmann::json& link_json);
  void modioInitLinkCpp(ModioLink* modio_link, const modio::Link* link);
  void modioFreeLink(ModioLink* link);
}

#endif
