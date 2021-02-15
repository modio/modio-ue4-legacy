#ifndef MODIO_TERMS_H
#define MODIO_TERMS_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioTag

namespace modio
{
  class Button
  {
  public:
    std::string text;

    void initialize(const ModioButton& button);
  };

  class Link
  {
  public:
    std::string text;
    std::string url;
    bool required;

    void initialize(const ModioLink& link);
  };

  class Terms
  {
  public:
    std::string plaintext;
    std::string html;

    Button agree;
    Button disagree;

    Link website;
    Link terms;
    Link privacy;
    Link manage;

    void initialize(const ModioTerms& terms);
  };

  extern nlohmann::json toJson(const Terms& terms);
} // namespace modio

#endif
