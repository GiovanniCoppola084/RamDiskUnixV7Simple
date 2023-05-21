#pragma once

#include "File.h"
#include "Directory.h"

typedef struct FileSystem {
	Inode *inodes[TOTAL_INODES];
	Directory *directories[TOTAL_DIRECTORIES];
	File *files[TOTAL_FILES];
	unsigned int inodeIndex;
	unsigned int directoryIndex;
	unsigned int fileIndex;
} FileSystem;

FileSystem CreateFileSystem();

void DeleteFileSystem(FileSystem *fs);

void CreateFileInDirectory(FileSystem *fs, string text, unsigned short mode);

void DeleteFileInDirectory();

void CreateDirectoryInDirectory();

void DeleteDirectoryInDirectory();

void CheckInodeIndex();