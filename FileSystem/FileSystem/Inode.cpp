#include "Inode.h"

Inode *CreateInode(string name, unsigned short numberActiveLinks, unsigned short sizeOfFile, bool isDirec) {
	Inode *inode = (Inode *)malloc(sizeof(Inode));
	
	if (inode == NULL) {
		cout << "PANIC: RAN OUT OF MEMORY" << endl;
		exit(0);
	}

	inode->name = name;
	inode->numberActiveLinks = numberActiveLinks;
	inode->sizeOfFile = sizeOfFile;
	inode->isDirectory = isDirec;
	return inode;
}

void DeleteInode(Inode *inode) {
	free(inode);
}

void IncreaseNumActivePointers(Inode *inode) {
	inode->numberActiveLinks++;
}

void DecreaseNumActivePointers(Inode *inode) {
	inode->numberActiveLinks--;
}