#ifndef __getpid_h__
#define __getpid_h__

#include <Windows.h>
#include <cstdlib>
#include<TlHelp32.h>

HANDLE ProcessPid2Handle( DWORD pid) {
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

DWORD ProcessName2Pid(char * ProcessName) {
	HANDLE processAll = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	tagPROCESSENTRY32 processEntry = {};
	processEntry.dwSize = sizeof(tagPROCESSENTRY32);
	DWORD processId = 0;
	do {
		if (strcmp(ProcessName, processEntry.szExeFile) == 0) {
			processId = processEntry.th32ProcessID;
			break;
		}
	} while (Process32Next(processAll, &processEntry));
	return processId;
}

#endif
