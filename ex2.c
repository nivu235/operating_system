#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        4096,
        L"MySharedMemory");

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    pBuf = (LPTSTR) MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 4096);

    if (pBuf == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    // Now you can use pBuf to read/write shared data

    // Unmap and close the file mapping object when done
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
