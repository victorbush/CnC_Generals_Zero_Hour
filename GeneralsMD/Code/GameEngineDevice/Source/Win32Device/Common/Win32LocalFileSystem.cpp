/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

///////// Win32LocalFileSystem.cpp /////////////////////////
// Bryan Cleveland, August 2002
////////////////////////////////////////////////////////////

#include <windows.h>
#include "Common/AsciiString.h"
#include "Common/GameMemory.h"
#include "Common/PerfTimer.h"
#include "Win32Device/Common/Win32LocalFileSystem.h"
#include "Win32Device/Common/Win32LocalFile.h"
#include <io.h>

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

Win32LocalFileSystem::Win32LocalFileSystem(const std::vector<std::experimental::filesystem::path>& prioritizedSearchPaths)
{
	if (prioritizedSearchPaths.size() == 0)
		throw std::invalid_argument("At least one base path must be provided to Win32LocalFileSystem.");

	// Force absolute paths using current working directory
	for (int i = 0; i < prioritizedSearchPaths.size(); i++)
	{
		if (prioritizedSearchPaths.at(i).is_relative())
			m_prioritizedSearchPaths.push_back(fs::current_path() / prioritizedSearchPaths.at(i));
		else
			m_prioritizedSearchPaths.push_back(prioritizedSearchPaths.at(i));
	}
}

Win32LocalFileSystem::~Win32LocalFileSystem() {
}

//DECLARE_PERF_TIMER(Win32LocalFileSystem_openFile)
File * Win32LocalFileSystem::openFile(const Char *filename, Int access /* = 0 */) 
{
	//USE_PERF_TIMER(Win32LocalFileSystem_openFile)
	Win32LocalFile *file = newInstance( Win32LocalFile );	

	// sanity check
	if (strlen(filename) <= 0) {
		return NULL;
	}

	fs::path filePath;

	if (access & File::WRITE) {
		filePath = getPreferredFilePath(filename);

		// if opening the file for writing, we need to make sure the directory is there
		// before we try to create the file.
		AsciiString string;
		string = filename;
		AsciiString token;
		AsciiString dirName;
		string.nextToken(&token, "\\/");
		dirName = token;
		while ((token.find('.') == NULL) || (string.find('.') != NULL)) {
			createDirectory(dirName);
			string.nextToken(&token, "\\/");
			dirName.concat('\\');
			dirName.concat(token);
		}
	}
	else
	{
		// Opening for read, find the file using search paths
		if (!tryFindFile(filename, filePath))
			return NULL;
	}

	if (file->open(filePath.string().c_str(), access) == FALSE) {
		file->close();
		file->deleteInstance();
		file = NULL;
	} else {
		file->deleteOnClose();
	}

// this will also need to play nice with the STREAMING type that I added, if we ever enable this

// srj sez: this speeds up INI loading, but makes BIG files unusable. 
// don't enable it without further tweaking.
//
// unless you like running really slowly.
//	if (!(access&File::WRITE)) {
//		// Return a ramfile.
//		RAMFile *ramFile = newInstance( RAMFile );
//		if (ramFile->open(file)) {
//			file->close(); // is deleteonclose, so should delete.
//			ramFile->deleteOnClose();
//			return ramFile;
//		}	else {
//			ramFile->close();
//			ramFile->deleteInstance();
//		}
//	}

	return file;
}

void Win32LocalFileSystem::update() 
{
}

void Win32LocalFileSystem::init() 
{
}

void Win32LocalFileSystem::reset() 
{
}

//DECLARE_PERF_TIMER(Win32LocalFileSystem_doesFileExist)
Bool Win32LocalFileSystem::doesFileExist(const Char *filename) const
{
	std::experimental::filesystem::path path;
	return findFile(filename, path);
}

Bool Win32LocalFileSystem::findFile(const Char* filename, std::experimental::filesystem::path& outAbsolutePath) const
{
	std::experimental::filesystem::path path;

	if (tryFindFile(filename, path))
	{
		outAbsolutePath = path;
		return TRUE;
	}

	return FALSE;
}

void Win32LocalFileSystem::getFileListInDirectory(const AsciiString& currentDirectory, const AsciiString& originalDirectory, const AsciiString& searchName, FilenameList & filenameList, Bool searchSubdirectories) const
{
	HANDLE fileHandle = NULL;
	WIN32_FIND_DATA findData;

	fs::path basePath = originalDirectory.str();
	basePath.concat(currentDirectory.str());

	if (!tryFindFile(basePath.string().c_str(), basePath))
		return;

	fs::path searchPath = basePath / searchName.str();
	if (searchPath.string().length() >= _MAX_PATH)
		throw std::invalid_argument("The path is too long");

	// char search[_MAX_PATH];
	// AsciiString asciisearch;
	// asciisearch = originalDirectory;
	// asciisearch.concat(currentDirectory);
	// asciisearch.concat(searchName);
	// strcpy(search, searchPath.string().c_str());

	Bool done = FALSE;

	fileHandle = FindFirstFile(searchPath.string().c_str(), &findData);
	done = (fileHandle == INVALID_HANDLE_VALUE);

	while (!done)	{
		if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
				(strcmp(findData.cFileName, ".") && strcmp(findData.cFileName, ".."))) {
			// if we haven't already, add this filename to the list.
				// a stl set should only allow one copy of each filename

				fs::path newFilePath = basePath / findData.cFileName;

				// AsciiString newFilename;
				// newFilename = originalDirectory;
				// newFilename.concat(currentDirectory);
				// newFilename.concat(findData.cFileName);
				if (filenameList.find(newFilePath.string().c_str()) == filenameList.end()) {
					filenameList.insert(newFilePath.string().c_str());
				}
		}

		done = (FindNextFile(fileHandle, &findData) == 0);
	}
	FindClose(fileHandle);

	if (searchSubdirectories) {
		fs::path subdirPath = basePath / "*.";

		// AsciiString subdirsearch;
		// subdirsearch = originalDirectory;
		// subdirsearch.concat(currentDirectory);
		// subdirsearch.concat("*.");
		fileHandle = FindFirstFile(subdirPath.string().c_str(), &findData);
		done = fileHandle == INVALID_HANDLE_VALUE;

		while (!done) {
			if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
					(strcmp(findData.cFileName, ".") && strcmp(findData.cFileName, ".."))) {

					fs::path tempSearchPath = basePath / findData.cFileName;

					// AsciiString tempsearchstr;
					// tempsearchstr.concat(currentDirectory);
					// tempsearchstr.concat(findData.cFileName);
					// tempsearchstr.concat('\\');

					// recursively add files in subdirectories if required.
					getFileListInDirectory(tempSearchPath.string().c_str(), originalDirectory, searchName, filenameList, searchSubdirectories);
			}

			done = (FindNextFile(fileHandle, &findData) == 0);
		}

		FindClose(fileHandle);
	}

}

Bool Win32LocalFileSystem::getFileInfo(const AsciiString& filename, FileInfo *fileInfo) const 
{
	fs::path filePath;
	if (!tryFindFile(filename.str(), filePath))
		return FALSE;

	WIN32_FIND_DATA findData;
	HANDLE findHandle = FindFirstFile(filePath.string().c_str(), &findData);
	if (findHandle == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	fileInfo->timestampHigh = findData.ftLastWriteTime.dwHighDateTime;
	fileInfo->timestampLow = findData.ftLastWriteTime.dwLowDateTime;
	fileInfo->sizeHigh = findData.nFileSizeHigh;
	fileInfo->sizeLow = findData.nFileSizeLow;

	FindClose(findHandle);

	return TRUE;
}

Bool Win32LocalFileSystem::createDirectory(AsciiString directory) 
{
	std::string path = getPreferredFilePath(directory.str()).string();

	if ((path.size() > 0) && (path.size() < _MAX_DIR)) {
		return (CreateDirectory(path.c_str(), NULL) != 0);
	}
	return FALSE;
}

Bool Win32LocalFileSystem::tryFindFile(const char* rawFileName, fs::path& outPath) const
{
	fs::path fileName = rawFileName;

	// For absolute paths there is nothing else to check except the path itself
	if (fileName.is_absolute() && exists(fileName))
	{
		outPath = fileName;
		return true;
	}

	// For relative paths, search using all base paths in order of priority
	for (const auto& basePath : m_prioritizedSearchPaths)
	{
		fs::path p = basePath / fileName;
		if (exists(p))
		{
			// Convert to absolute path before returning
			outPath = fs::absolute(p);
			return true;
		}
	}

	return false;
}

fs::path Win32LocalFileSystem::getPreferredFilePath(const char* fileOrDir) const
{
	fs::path path = fileOrDir;

	// The preferred file path is either:
	// 1. The input path (if absolute)
	// 2. The input path relative to the first base path given to this LocalFileSystem

	if (path.is_absolute())
		return path;

	return m_prioritizedSearchPaths.front() / fileOrDir;
}
