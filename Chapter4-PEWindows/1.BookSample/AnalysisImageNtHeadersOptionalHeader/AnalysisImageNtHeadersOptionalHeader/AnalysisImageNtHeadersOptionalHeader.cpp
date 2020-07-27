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
		printf("(WORD)Magic is %04X\n", NT_HEADERS.OptionalHeader.Magic);
		//_IMAGE_OPTIONAL_HEADER的大小已經由IMAGE_FILE_HEADER當中的SizeOfOptionalHeader來決定
		//所以不需要寫sizeof(struct _IMAGE_OPTIONAL_HEADER來證明_IMAGE_OPTIONAL_HEADER的大小)
		printf("(BYTE)MajorLinkerVersion is %02X\n", NT_HEADERS.OptionalHeader.MajorLinkerVersion);
		printf("(BYTE)MinorLinkerVersion is %02X\n", NT_HEADERS.OptionalHeader.MinorLinkerVersion);
		printf("(DWORD)SizeOfCode is %08X\n", NT_HEADERS.OptionalHeader.SizeOfCode);
		printf("(DWORD)SizeOfInitializedData is %08X\n", NT_HEADERS.OptionalHeader.SizeOfInitializedData);
		printf("(DWORD)SizeOfUninitializedData is %08X\n", NT_HEADERS.OptionalHeader.SizeOfUninitializedData);
		printf("(DWORD)AddressOfEntryPoint is %08X\n", NT_HEADERS.OptionalHeader.AddressOfEntryPoint);
		printf("(DWORD)BaseOfCode is %08X\n", NT_HEADERS.OptionalHeader.BaseOfCode);
		printf("(DWORD)BaseOfData is %08X\n", NT_HEADERS.OptionalHeader.BaseOfData);
		printf("(DWORD)SectionAlignment is %08X\n", NT_HEADERS.OptionalHeader.SectionAlignment);
		printf("(DWORD)FileAlignment is %08X\n", NT_HEADERS.OptionalHeader.FileAlignment);
		printf("(WORD)MajorOperatingSystemVersion is %04X\n", NT_HEADERS.OptionalHeader.MajorOperatingSystemVersion);
		printf("(WORD)MinorOperatingSystemVersion is %04X\n", NT_HEADERS.OptionalHeader.MinorOperatingSystemVersion);
		printf("(WORD)MajorImageVersion is %04X\n", NT_HEADERS.OptionalHeader.MajorImageVersion);
		printf("(WORD)MinorImageVersion is %04X\n", NT_HEADERS.OptionalHeader.MinorImageVersion);
		printf("(WORD)MajorSubsystemVersion is %04X\n", NT_HEADERS.OptionalHeader.MajorSubsystemVersion);
		printf("(WORD)MinorSubsystemVersion is %04X\n", NT_HEADERS.OptionalHeader.MinorSubsystemVersion);
		printf("(DWORD)Win32VersionValue is %08X\n", NT_HEADERS.OptionalHeader.Win32VersionValue);
		printf("(DWORD)SizeOfImage is %08X\n", NT_HEADERS.OptionalHeader.SizeOfImage);
		printf("(DWORD)SizeOfHeaders is %08X\n", NT_HEADERS.OptionalHeader.SizeOfHeaders);
		printf("(DWORD)CheckSum is %08X\n", NT_HEADERS.OptionalHeader.CheckSum);
		printf("(WORD)Subsystem is %04X\n", NT_HEADERS.OptionalHeader.Subsystem);
		printf("(WORD)DllCharacteristics is %04X\n", NT_HEADERS.OptionalHeader.DllCharacteristics);
		printf("(DWORD)SizeOfStackReserve is %08X\n", NT_HEADERS.OptionalHeader.SizeOfStackReserve);
		printf("(DWORD)SizeOfStackCommit is %08X\n", NT_HEADERS.OptionalHeader.SizeOfStackCommit);
		printf("(DWORD)SizeOfHeapReserve is %08X\n", NT_HEADERS.OptionalHeader.SizeOfHeapReserve);
		printf("(DWORD)SizeOfHeapCommit is %08X\n", NT_HEADERS.OptionalHeader.SizeOfHeapCommit);
		printf("(DWORD)LoaderFlags is %08X\n", NT_HEADERS.OptionalHeader.LoaderFlags);
		printf("(DWORD)NumberOfRvaAndSizes is %08X\n", NT_HEADERS.OptionalHeader.NumberOfRvaAndSizes);
	}
	system("pause");
	return 0;
}
