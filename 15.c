#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define BUFFER_SIZE 1024
#define SHARED_MEMORY_NAME "MySharedMemory"

int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;

    // Create or open a file mapping object
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        BUFFER_SIZE,
        SHARED_MEMORY_NAME);

    if (hMapFile == NULL) {
        perror("CreateFileMapping");
        return 1;
    }

    // Map the file mapping object to a process's address space
    pBuf = MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUFFER_SIZE);

    if (pBuf == NULL) {
        perror("MapViewOfFile");
        CloseHandle(hMapFile);
        return 1;
    }

    // Write data to the shared memory
    char data[] = "Hello, Shared Memory!";
    strncpy((char*)pBuf, data, sizeof(data));

    // Unmap and close the file mapping object when done
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
