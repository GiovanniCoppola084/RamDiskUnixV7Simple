/**
*	Inlcude metadata about the system in the form of an Inode array
*/

#pragma once

#include "Standard.h"

typedef struct Inode {
	string name;
	unsigned short numberActiveLinks;
	unsigned short sizeOfFile;
	bool isDirectory;
} Inode;

Inode CreateInode(string name, unsigned short numberActiveLinks, unsigned short sizeOfFile, bool isDirec);

void DeleteInode(Inode *inode);

void IncreaseNumActivePointers(Inode *inode);

void DecreaseNumActivePointers(Inode *inode);