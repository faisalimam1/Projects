
// main.c

#include "../include/vfs.h"

VirtualFileSystem vfs;

void initialize_vfs() {
    vfs.file_count = 0;
    memset(vfs.data, 0, sizeof(vfs.data));
    for (int i = 0; i < MAX_FILES; ++i) {
        vfs.files[i].used = 0;
    }
    printf("✅ Virtual File System Initialized\n");
}

int main() {
    initialize_vfs();

    // add CLI or test calls
    return 0;
}
