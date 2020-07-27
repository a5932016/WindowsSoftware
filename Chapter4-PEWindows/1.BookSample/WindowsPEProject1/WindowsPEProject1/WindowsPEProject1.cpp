#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <tchar.h>

IMAGE_DOS_HEADER DOS_HEADER;

int _tmain(int argc,_TCHAR* argv[])
{
	FILE* pfile;
	errno_t error;

	if ((error = fopen_s(&pfile, "C:/EmptyProject1.exe", "r")) != 0)
	{
		printf("無法開啟文件"); getchar();
	}
	else
	{
		fread(&DOS_HEADER, sizeof(struct _IMAGE_DOS_HEADER), 1, pfile);

		printf("(WORD)e_magic     is %04X\n", DOS_HEADER.e_magic);
		printf("(WORD)e_cblp      is %04X\n", DOS_HEADER.e_cblp);
		printf("(WORD)e_cp        is %04X\n", DOS_HEADER.e_cp);
		printf("(WORD)e_crlc      is %04X\n", DOS_HEADER.e_crlc);
		printf("(WORD)e_cparhdr   is %04X\n", DOS_HEADER.e_cparhdr);
		printf("(WORD)e_minalloc  is %04X\n", DOS_HEADER.e_minalloc);
		printf("(WORD)e_maxalloc  is %04X\n", DOS_HEADER.e_maxalloc);
		printf("(WORD)e_ss        is %04X\n", DOS_HEADER.e_ss);
		printf("(WORD)e_sp        is %04X\n", DOS_HEADER.e_sp);
		printf("(WORD)e_csum      is %04X\n", DOS_HEADER.e_csum);
		printf("(WORD)e_ip        is %04X\n", DOS_HEADER.e_ip);
		printf("(WORD)e_cs        is %04X\n", DOS_HEADER.e_cs);
		printf("(WORD)e_lfarlc    is %04X\n", DOS_HEADER.e_lfarlc);
		printf("(WORD)e_ovno      is %04X\n", DOS_HEADER.e_ovno);

		for (int i = 0; i < 4; i++)
		{
			printf("(WORD)e_res[&d]   is %04X\n", i, DOS_HEADER.e_res[i]);
		}

		printf("(WORD)e_oemid     is %04X\n", DOS_HEADER.e_oemid);
		printf("(WORD)e_oeminfo   is %04X\n", DOS_HEADER.e_oeminfo);

		for (int i = 0; i < 10; i++)
		{
			printf("(WORD)e_res2[&d]  is %04X\n", i, DOS_HEADER.e_res2[i]);
		}

		printf("(WORD)e_lfanew    is %04X\n", DOS_HEADER.e_lfanew);
		printf("sizeof IMAFE_DOS_HEADER is %d bytes", sizeof(DOS_HEADER));
	}

	system("pause");
	return 0;
}