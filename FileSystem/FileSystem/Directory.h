#pragma once

#include "Inode.h"

typedef struct Directory {
	void* pointers[TOTAL_NUM_ITEMS_PER_DIRECTORY];
	unsigned int parentDirectoryIndex;
	unsigned short inodeIntoInode;
	unsigned short pointersInUse;
} Directory;

Directory CreateDirectory();

void DeleteDirectory(Directory *directory);