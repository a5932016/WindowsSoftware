#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>

IMAGE_DOS_HEADER DOS_HEADER;
IMAGE_NT_HEADERS NT_HEADERS;

int _tmain(int argc, _TCHAR* argv[]) {
	HANDLE hFile = CreateFile(
		_T("C:/EmptyProject1.exe"), 
		GENERIC_READ,
		FILE_SHARE_READ, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL);

	ReadFile(hFile, &DOS_HEADER, sizeof(DOS_HEADER), NULL, NULL);
	SetFilePointer(hFile, DOS_HEADER.e_lfanew, NULL, FILE_BEGIN);
	ReadFile(hFile, &NT_HEADERS, sizeof(NT_HEADERS), NULL, NULL);

	if (NT_HEADERS.Signature == 0x00004550) {
		printf("這是對PE標誌的判斷，這是PE文件\r\n");
	}
	else {
		printf("這是對PE標誌的判斷，這不是PE文件\r\n");
	}

	system("pause");
	return 0;
}