#ifndef MODIO_UTILITY_H
#define MODIO_UTILITY_H

#ifdef __linux__
#define MODIO_LINUX_DETECTED
#endif

#ifdef __APPLE__
#define MODIO_OSX_DETECTED
#endif
#ifdef __MACH__
#define MODIO_OSX_DETECTED
#endif

#ifdef _WIN32
#define MODIO_WINDOWS_DETECTED
#endif
#ifdef _WIN64
#define MODIO_WINDOWS_DETECTED
#endif

#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_MAC) || defined(PLATFORM_WINDOWS)
#  define MODIO_UE4_DETECTED
#endif

#ifndef PATH_MAX
#define PATH_MAX 260
#endif

#include "dependencies/nlohmann/json.hpp"        // for json, basic_json<>::...
#include "c/ModioC.h"

namespace modio
{
// String methods
std::string MODIO_DLL toString(i32 number);
std::string MODIO_DLL toString(u32 number);
std::string MODIO_DLL toString(double number);
std::string replaceSubstrings(const std::string &str, const std::string &from, const std::string &to);
std::string addSlashIfNeeded(const std::string &directory_path);
std::string getFilename(std::string file_path);
std::string getFileExtension(std::string path);

// Log methods
void writeLogLine(const std::string &text, u32 debug_level);
void clearLog();

// Time methods
u32 getCurrentTimeSeconds();
double getCurrentTimeMillis();

// Json methods
bool hasKey(nlohmann::json json_object, const std::string &key);
nlohmann::json toJson(const std::string &json_str);
nlohmann::json openJson(const std::string &file_path);
void writeJson(const std::string &file_path, nlohmann::json json_object);

// Filesystem methods
std::string getModIODirectory();
std::vector<std::string> getFilenames(const std::string &directory);
std::vector<std::string> getDirectoryNames(const std::string &root_directory);
bool isDirectory(const std::string &directory);
bool directoryExists(const std::string &path);
bool fileExists(const std::string &directory);
std::string getDirectoryPath(const std::string &filename);
bool createDirectory(const std::string &directory);
bool removeDirectory(const std::string &directory);
void removeFile(const std::string &filename);
double getFileSize(const std::string &file_path);
void createPath(const std::string &strPathAndFile);
std::vector<std::string> getHeaders();
std::vector<std::string> getHeadersNoToken();
std::vector<std::string> getUrlEncodedHeaders();
std::string base64Encode(unsigned char const* bytes_to_encode, unsigned int in_len);
std::string getMyDocumentsPath();
std::string randomString(u32 length);
} // namespace modio

#endif
