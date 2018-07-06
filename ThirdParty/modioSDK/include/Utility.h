#ifndef MODIO_UTILITY_H
#define MODIO_UTILITY_H

#ifdef __linux__
#define LINUX
#endif

#ifdef __APPLE__
#define OSX
#endif
#ifdef __MACH__
#define OSX
#endif

#ifdef _WIN32
#define WINDOWS
#endif
#ifdef _WIN64
#define WINDOWS
#endif

#ifdef WINDOWS
#ifdef BUILDING_MODIO_DLL
#define MODIO_DLL __declspec(dllexport)
#else
#define MODIO_DLL __declspec(dllimport)
#endif
#else
#define MODIO_DLL
#endif

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

#include "c/ModioC.h"
#include "dependencies/json/json.hpp"
#include "Globals.h"

#ifdef LINUX
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#endif

#ifdef WINDOWS
#include <windows.h>
#include <strsafe.h>
#include "dependencies/dirent/dirent.h"
#endif

#ifdef OSX
#include <sys/stat.h>
#include <dirent.h>
#endif

using json = nlohmann::json;

#ifndef PATH_MAX
#define PATH_MAX 260
#endif

namespace modio
{
std::string MODIO_DLL toString(i32 number);
std::string MODIO_DLL toString(u32 number);
std::string MODIO_DLL toString(double number);
void createDirectory(std::string directory);
void clearLog();
void writeLogLine(std::string text, unsigned int debug_level);
std::vector<std::string> getFilenames(std::string directory);
std::string getModIODirectory();
bool hasKey(json json_object, std::string key);
void removeFile(std::string filename);
bool removeDirectory(std::string directory_name);
std::string addSlashIfNeeded(std::string directory_path);
json toJson(std::string json_str);
json openJson(std::string file_path);
void writeJson(std::string file_path, json json_object);
u32 getCurrentTime();
double getFileSize(std::string file_path);
void createPath(std::string strPathAndFile);
std::string replaceSubstrings(std::string str, const std::string &from, const std::string &to);
}

#endif
