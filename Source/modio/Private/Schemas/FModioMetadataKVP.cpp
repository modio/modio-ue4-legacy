// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioMetadataKVP.h"

void InitializeMetadataKVP(FModioMetadataKVP &MetadataKVP, const ModioMetadataKVP &modio_metadata_kvp)
{
  MetadataKVP.Metakey = UTF8_TO_TCHAR(modio_metadata_kvp.metakey);
  MetadataKVP.Metavalue = UTF8_TO_TCHAR(modio_metadata_kvp.metavalue);
}