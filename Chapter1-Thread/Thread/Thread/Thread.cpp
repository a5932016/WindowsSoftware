// Thread.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <winnt.h>

#define MAX_CUSTOMER 100
#define TOTAL_CLERK 4

volatile LONGLONG Customer_Number = 0;
volatile LONGLONG Customer_Serving = 0;
HANDLE Clerk_Semaphore = NULL;
INT Customer_Counter[MAX_CUSTOMER];

UINT _stdcall Clerk(PVOID lp)
{
	INT Clerk_Number = *(INT*)lp;
	while (Customer_Number < MAX_CUSTOMER)
	{
		WaitForSingleObject(Clerk_Semaphore, INFINITE);
		INT i = InterlockedIncrement64(&Customer_Number) - 1;
		printf("Serve Customer %2d by Clerk %d (%d)\n", i, Clerk_Number, InterlockedIncrement64(&Customer_Serving));
		Sleep(rand() % 4);
		printf("Serve Customer %2d by Clerk %d (%d) done\n", i, Clerk_Number, InterlockedDecrement64(&Customer_Serving));
		ReleaseSemaphore(Clerk_Semaphore, 1, NULL);
		Customer_Counter[i]++;
	}

	return 0;
}

int main()
{
	HANDLE Clerk_Handle[TOTAL_CLERK];
	INT Clerk_Numbers[TOTAL_CLERK];
	srand(GetTickCount());
	Clerk_Semaphore = CreateSemaphore(NULL, TOTAL_CLERK, TOTAL_CLERK, NULL);
	ZeroMemory(Customer_Counter, sizeof(Customer_Counter));

	for (int i = 0; i < TOTAL_CLERK; i++)
	{
		Clerk_Numbers[i] = i;
		Clerk_Handle[i] = (HANDLE)_beginthreadex(NULL, 0, Clerk, &Clerk_Numbers[i], CREATE_SUSPENDED, NULL);
	}

	printf("Stuffs are ready\n");

	for (int i = 0; i < TOTAL_CLERK; i++)
	{
		ResumeThread(Clerk_Handle[i]);
	}

	WaitForMultipleObjects(TOTAL_CLERK, Clerk_Handle, TRUE, INFINITE);

	for (int i = 0; i < MAX_CUSTOMER; i++)
	{
		printf("Customer %2d processed by %d Clerks\n", i, Customer_Counter[i]);
	}

	CloseHandle(Clerk_Semaphore);
	system("pause");
	return 0;
}


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
