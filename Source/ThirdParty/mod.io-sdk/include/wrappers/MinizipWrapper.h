#ifndef MODIO_MINIZIP_WRAPPER_H
#define MODIO_MINIZIP_WRAPPER_H

#include <string>  // for string
#include <vector>  // for vector

#define dir_delimter '/'
#define MAX_FILENAME 512
#define READ_SIZE 8192

namespace modio
{
  namespace minizipwrapper
  {
    void extract(std::string zip_path, std::string directory_path);
    void compressDirectory(std::string directory, std::string zip_path);
    void compressFiles(std::string root_directory, std::vector<std::string> filenames, std::string zip_path);
  }
}

#endif
