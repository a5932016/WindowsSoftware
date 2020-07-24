// ThreadProcess.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

INT _tmain(INT argc,LPCTSTR argv[])
{
	TCHAR szCommandLine[] = _T("calc.exe");
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	BOOL bProcess = CreateProcess(
		NULL,
		szCommandLine,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	system("pause");
	return 0;
}
