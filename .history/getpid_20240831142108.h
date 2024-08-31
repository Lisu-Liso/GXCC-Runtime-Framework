#ifndef __getpid_h__
#define __getpid_h__

#include <Windows.h>
#include <TlHelp32.h>
#include <cstdlib>
#include <cstring> // for strcmp

HANDLE ProcessPid2Handle(DWORD pid) {
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

DWORD ProcessName2Pid(const char* processName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return 0; // Snapshot creation failed
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snapshot, &processEntry)) {
        CloseHandle(snapshot);
        return 0; // First process retrieval failed
    }

    DWORD processId = 0;
    do {
        if (strcmp(processName, processEntry.szExeFile) == 0) {
            processId = processEntry.th32ProcessID;
            break;
        }
    } while (Process32Next(snapshot, &processEntry));

    CloseHandle(snapshot);
    return processId;
}

#endif // __getpid_h__
