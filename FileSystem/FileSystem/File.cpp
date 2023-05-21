#include "File.h"

File *CreateFile(string text, short mode) {
	File *file = (File *)malloc(sizeof(File));
	
	if (file == NULL) {
		cout << "PANIC: RAN OUT OF MEMORY" << endl;
		exit(0);
	}

	file->data = text;
	file->indexIntoInode = current_max_inode_index++;
	file->mode = mode;
	return file;
}

void DeleteFile(File *file) {
	free(file);
}

void WriteFile(File *file, string text) {
	if (file->mode != WRITE_AND_READ) {
		cout << "PANIC: You cannot access this file" << endl;
		exit(0);
	}

	file->data = text;
}

string ReadFile(File *file) {
	return file->data;
}

void PurgeFile(File *file) {
	file->data = "\0";
}