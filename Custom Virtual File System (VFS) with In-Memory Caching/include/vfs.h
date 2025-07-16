// vfs.h

#ifndef VFS_H
#define VFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILENAME 32
#define MAX_FILE_SIZE 1024  // In bytes
#define STORAGE_SIZE (MAX_FILES * MAX_FILE_SIZE)

// Metadata for each file
typedef struct {
    char name[MAX_FILENAME];
    int size;
    int start_block;
    int used;  // 0 = empty, 1 = used
    time_t created_at;
    time_t modified_at;
} FileEntry;

// The whole VFS structure
typedef struct {
    char data[STORAGE_SIZE];         // Memory buffer
    FileEntry files[MAX_FILES];      // Table of files
    int file_count;                  // Number of files used
} VirtualFileSystem;

void create_file(const char *filename);

#endif
