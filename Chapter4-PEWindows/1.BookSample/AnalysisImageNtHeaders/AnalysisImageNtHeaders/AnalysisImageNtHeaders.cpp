#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>
IMAGE_DOS_HEADER DOS_HEADER;
IMAGE_NT_HEADERS NT_HEADERS;
int _tmain(int argc, _TCHAR* argv[])
{
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
		printf("(DWORD)Signature is %08X\n", NT_HEADERS.Signature);
		printf("(WORD)Machine is %04X\n", NT_HEADERS.FileHeader.Machine);
		printf("(WORD)NumberOfSections is %04X\n", NT_HEADERS.FileHeader.NumberOfSections);
		printf("(DWORD)TimeDateStamp is %08X\n", NT_HEADERS.FileHeader.TimeDateStamp);
		printf("(DWORD)PointerToSymbolTable is %08X\n", NT_HEADERS.FileHeader.PointerToSymbolTable);
		printf("(DWORD)NumberOfSymbols is %08X\n", NT_HEADERS.FileHeader.NumberOfSymbols);
		printf("(WORD)SizeOfOptionalHeader is %04X\n", NT_HEADERS.FileHeader.SizeOfOptionalHeader);
		printf("(WORD)Characteristics is %04X\n", NT_HEADERS.FileHeader.Characteristics);
		printf("sizeof IMAGE_FILE_HEADER is %d bytes", sizeof(_IMAGE_FILE_HEADER));
	}
	system("pause");
	return 0;
}
