#include "FModioMetadataKVP.h"

void initializeMetadataKVP(FModioMetadataKVP &MetadataKVP, modio::MetadataKVP modio_metadata_kvp)
{
  MetadataKVP.Metakey = UTF8_TO_TCHAR(modio_metadata_kvp.metakey.c_str());
  MetadataKVP.Metavalue = UTF8_TO_TCHAR(modio_metadata_kvp.metavalue.c_str());
}

void initializeMetadataKVPC(FModioMetadataKVP &MetadataKVP, ModioMetadataKVP modio_metadata_kvp)
{
  MetadataKVP.Metakey = UTF8_TO_TCHAR(modio_metadata_kvp.metakey);
  MetadataKVP.Metavalue = UTF8_TO_TCHAR(modio_metadata_kvp.metavalue);
}