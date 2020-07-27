#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>
IMAGE_DOS_HEADER DOS_HEADER;
IMAGE_NT_HEADERS NT_HEADERS;
IMAGE_SECTION_HEADER SECTION_HEADER;
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
		fread(&SECTION_HEADER, sizeof(struct _IMAGE_SECTION_HEADER), 1, pfile);
		for (int i = 0; i < 8; i++) {
			printf("(BYTE)Name is %02X\n", SECTION_HEADER.Name[i]);
		}
		printf("(DWORD)PhysicalAddress is %08X\n", SECTION_HEADER.Misc.PhysicalAddress);
		printf("(DWORD)VirtualSize is %08X\n", SECTION_HEADER.Misc.VirtualSize);
		printf("(DWORD)VirtualAddress is %08X\n", SECTION_HEADER.VirtualAddress);
		printf("(DWORD)SizeOfRawData is %08X\n", SECTION_HEADER.SizeOfRawData);
		printf("(DWORD)PointerToRawData is %08X\n", SECTION_HEADER.PointerToRawData);
		printf("(DWORD)PointerToRelocations is %08X\n", SECTION_HEADER.PointerToRelocations);
		printf("(DWORD)PointerToLinenumbers is %08X\n", SECTION_HEADER.PointerToLinenumbers);
		printf("(WORD)NumberOfRelocations is %04X\n", SECTION_HEADER.NumberOfRelocations);
		printf("(WORD)NumberOfLinenumbers is %04X\n", SECTION_HEADER.NumberOfLinenumbers);
		printf("(DWORD)Characteristics is %08X\n", SECTION_HEADER.Characteristics);
	}
	system("pause");
	return 0;
}
