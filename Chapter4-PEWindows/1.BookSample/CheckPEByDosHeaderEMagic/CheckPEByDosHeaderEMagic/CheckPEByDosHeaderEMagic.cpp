#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>
IMAGE_DOS_HEADER DOS_HEADER;
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

		if (DOS_HEADER.e_magic == 0x5a4d) {
			printf("這是對MZ頭的判斷，這是PE文件\r\n");
		}
		else {
			printf("這是對MZ頭的判斷，這不是PE文件\r\n");
		}
	}

	system("pause");
	return 0;
}
