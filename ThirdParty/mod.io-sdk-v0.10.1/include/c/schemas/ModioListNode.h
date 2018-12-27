#ifndef MODIO_MODIOLISTNODE_H
#define MODIO_MODIOLISTNODE_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitNode(ModioListNode* node);
  void modioFreeNodeList(ModioListNode* node_list);
}

#endif
