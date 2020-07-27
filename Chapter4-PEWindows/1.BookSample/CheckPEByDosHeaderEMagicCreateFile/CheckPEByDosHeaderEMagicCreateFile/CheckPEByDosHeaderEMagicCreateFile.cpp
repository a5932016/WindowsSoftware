#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>

IMAGE_DOS_HEADER DOS_HEADER;

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

	if (DOS_HEADER.e_magic == 0x5a4d) {
		printf("這是對MZ頭的判斷，這是PE文件\n");
	}
	else {
		printf("這是對MZ頭的判斷，這不是PE文件\n");
	}

	system("pause");
	return 0;
}
