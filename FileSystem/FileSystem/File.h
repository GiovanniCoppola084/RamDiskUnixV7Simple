#pragma once

#include "Inode.h"

typedef struct File {
	string data;
	unsigned short indexIntoInode;
	unsigned short mode;
} File;

File CreateFile(string text, short mode);

void DeleteFile(File *file, string text);

void WriteFile(File *file);

string ReadFile(File *file);

void PurgeFile(File *file);