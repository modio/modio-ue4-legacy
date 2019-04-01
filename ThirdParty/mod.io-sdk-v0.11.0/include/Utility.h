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

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <chrono>

#include "c/ModioC.h"
#include "dependencies/nlohmann/json.hpp"
#include "dependencies/minizip/minizip.h"
#include "Globals.h"

#ifdef MODIO_LINUX_DETECTED
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#endif

#ifdef MODIO_WINDOWS_DETECTED
#  ifdef MODIO_UE4_DETECTED 
#    include <Windows/MinWindows.h>
#  else
#    include <windows.h>
#  endif
#  include <strsafe.h>
#  include "dependencies/dirent/dirent.h"
//#include "vld.h"
#endif

#ifdef MODIO_OSX_DETECTED
#include <sys/stat.h>
#include <dirent.h>
#endif

#ifndef PATH_MAX
#define PATH_MAX 260
#endif

namespace modio
{
// String methods
std::string MODIO_DLL toString(i32 number);
std::string MODIO_DLL toString(u32 number);
std::string MODIO_DLL toString(double number);
std::string replaceSubstrings(const std::string &str, const std::string &from, const std::string &to);
std::string addSlashIfNeeded(const std::string &directory_path);

// Log methods
void writeLogLine(const std::string &text, u32 debug_level);
void clearLog();

// Time methods
u32 getCurrentTime();
double getCurrentTimeMillis();

// Json methods
bool hasKey(nlohmann::json json_object, const std::string &key);
nlohmann::json toJson(const std::string &json_str);
nlohmann::json openJson(const std::string &file_path);
void writeJson(const std::string &file_path, nlohmann::json json_object);

// Filesystem methods
std::string getModIODirectory();
std::vector<std::string> getFilenames(const std::string &directory);
bool isDirectory(const std::string &directory);
bool directoryExists(const std::string &path);
bool fileExists(const std::string &directory);
std::string getDirectoryPath(const std::string &filename);
void createDirectory(const std::string &directory);
bool removeDirectory(const std::string &directory);
void removeFile(const std::string &filename);
double getFileSize(const std::string &file_path);
void createPath(const std::string &strPathAndFile);
std::vector<std::string> getHeaders();
std::vector<std::string> getUrlEncodedHeaders();
std::string base64Encode(unsigned char const* bytes_to_encode, unsigned int in_len);
} // namespace modio

#endif
