#include "FileSystem.h"

FileSystem *CreateFileSystem() {
	FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));

	if (fs == NULL) {
		cout << "PANIC: RAN OUT OF MEMORY" << endl;
		exit(0);
	}

	fs->inodes = {};
	fs->directories = {};
	fs->files = {};
	fs->current_max_inode_index = 0;
	fs->inodeIndex = 0;
	fs->directoryIndex = 0;
	fs->fileIndex = 0;
	return fs;
}

void DeleteFileSystem(FileSystem *fs) {
	free(fs);
}

void CreateFileInDirectory(FileSystem *fs, string text, unsigned short mode, string name) {
	CheckInodeIndex(fs);
	fs->files[fs->fileIndex++] = CreateFile(text, mode);
	fs->inodes[fs->inodeIndex++] = CreateInode(name, 0, text.length, false);
}

void DeleteFileInDirectory(FileSystem *fs, unsigned int index) {
	File *temp = fs->files[index];
	DeleteInode(fs->inodes[temp->indexIntoInode]);
	DeleteFile(fs->files[index]);
}

void WriteToFileInDirectory(FileSystem *fs, unsigned int index, string text) {
	CheckInodeIndex(fs);
	WriteFile(fs->files[index], text);
	File *temp = fs->files[index];
	unsigned int index = temp->indexIntoInode;
	fs->inodes[index]->sizeOfFile = text.length();

	cout << "New text in file: " << temp->text;
}

void CreateDirectoryInDirectory() {

}

void DeleteDirectoryInDirectory() {

}

void CheckInodeIndex(FileSystem *fs) {
	if (fs->inodeIndex >= TOTAL_INODES) {
		cout << "Too many inodes created" << endl;
		exit(0);
	}
}