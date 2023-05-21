#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#define FILE_SIZE 1024
#define NAME_SIZE 16
#define TOTAL_DIRECTORIES 1024
#define TOTAL_FILES 65536
#define TOTAL_INODES (TOTAL_FILES * TOTAL_DIRECTORIES)
#define TOTAL_NUM_ITEMS_PER_DIRECTORY 64
#define DEPRICATED 0
#define READ_ONLY 1
#define WRITE_AND_READ 2

using namespace std;