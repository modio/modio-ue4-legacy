#ifndef MODIO_MODIOLISTNODE_H
#define MODIO_MODIOLISTNODE_H

#include "../ModioC.h"                     // for ModioListNode
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitNode(ModioListNode* node);
  void modioFreeNodeList(ModioListNode* node_list);
}

#endif
