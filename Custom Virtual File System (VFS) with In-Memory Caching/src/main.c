// main.c

#include "../include/vfs.h"

VirtualFileSystem vfs;

void initialize_vfs() {
    vfs.file_count = 0;
    memset(vfs.data, 0, sizeof(vfs.data));
    for (int i = 0; i < MAX_FILES; ++i) {
        vfs.files[i].used = 0;
    }
    printf("Virtual File System Initialized\n");
}

int main() {
    initialize_vfs();
    
    // 1st function- create a new file
    void create_file(const char *filename) {
    if (vfs.file_count >= MAX_FILES) {
        printf("Error: File limit reached.\n");
        return;
    }

    // Check if file already exists
    for (int i = 0; i < MAX_FILES; ++i) {
        if (vfs.files[i].used && strcmp(vfs.files[i].name, filename) == 0) {
            printf("Error: File '%s' already exists.\n", filename);
            return;
        }
    }

    // Find an unused entry
    for (int i = 0; i < MAX_FILES; ++i) {
        if (!vfs.files[i].used) {
            strcpy(vfs.files[i].name, filename);
            vfs.files[i].size = 0;
            vfs.files[i].start_block = i * MAX_FILE_SIZE;
            vfs.files[i].used = 1;
            vfs.files[i].created_at = time(NULL);
            vfs.files[i].modified_at = time(NULL);
            vfs.file_count++;

            printf("File '%s' created successfully.\n", filename);
            return;
        }
    }

    printf("Error: Could not create file.\n");
}

    create_file("file1.txt");
    create_file("notes.txt");
    create_file("file1.txt");

    // add more test calls here
    return 0;
}
