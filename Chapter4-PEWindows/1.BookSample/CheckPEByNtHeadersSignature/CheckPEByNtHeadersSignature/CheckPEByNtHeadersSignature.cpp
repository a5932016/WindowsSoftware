#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>
IMAGE_DOS_HEADER DOS_HEADER;
IMAGE_NT_HEADERS NT_HEADERS;
int _tmain(int argc, _TCHAR* argv[]) {
	FILE* pfile;
	errno_t error;
	if ((error = fopen_s(&pfile, "C:/EmptyProject1.exe", "r")) != 0)
	{
		printf("無法開啟文件");
		getchar();
	}
	else {
		fread(&DOS_HEADER, sizeof(struct _IMAGE_DOS_HEADER), 1, pfile);
		fseek(pfile, DOS_HEADER.e_lfanew, 0);
		fread(&NT_HEADERS, sizeof(struct _IMAGE_NT_HEADERS), 1, pfile);

		if (NT_HEADERS.Signature == 0x00004550) {
			printf("這是對PE標誌的判斷，這是PE文件\r\n");
		}
		else {
			printf("這是對PE標誌的判斷，這不是PE文件\r\n");
		}
	}

	system("pause");
	return 0;
}
