#include <windows.h>
#include <stdio.h>

int main() {
    // Create a new process
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi);

    if (CreateProcess(
        L"C:\Users\Dell\OneDrive\Documents\add.exe", // Replace with the path to your desired program
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi))
    {
        printf("New process created with Process ID: %d\n", pi.dwProcessId);

        // Get the process identifier of the currently running process
        DWORD currentProcessId = GetCurrentProcessId();
        printf("Current Process ID: %d\n", currentProcessId);

        // Get the parent process identifier
        DWORD parentProcessId = GetParentProcessId(GetCurrentProcessId());
        printf("Parent Process ID: %d\n", parentProcessId);
    }
    else {
        printf("Error creating a new process: %d\n", GetLastError());
    }

    return 0;
}

// Function to get the parent process identifier
DWORD GetParentProcessId(DWORD processId) {
    DWORD parentProcessId = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
        if (Process32First(hSnapshot, &pe32)) {
            do {
                if (pe32.th32ProcessID == processId) {
                    parentProcessId = pe32.th32ParentProcessID;
                    break;
                }
            } while (Process32Next(hSnapshot, &pe32));
        }
        CloseHandle(hSnapshot);
    }
    return parentProcessId;
}

