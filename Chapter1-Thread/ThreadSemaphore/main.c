#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <winnt.h>

#define MAX_CUSTOMER 100
#define TOTAL_CLERK 4

volatile INT Customer_Number = 0;
volatile INT Customer_Serving = 0;
HANDLE Clerk_Semaphore = NULL;
INT Customer_Counter[MAX_CUSTOMER];

UINT _stdcall Clerk(PVOID lp)
{
    INT Clerk_Number = *(INT*)lp;
    while(Customer_Number < MAX_CUSTOMER)
    {
        WaitForSingleObject(Clerk_Semaphore,INFINITE);
        INT i = Customer_Number;
        printf("Serve Customer %2d by Clerk %d (%d)\n",i,Clerk_Number,Customer_Serving);
        Sleep(rand() % 4);
        printf("Serve Customer %2d by Clerk %d (%d) done\n",i,Clerk_Number,Customer_Serving);
        ReleaseSemaphore(Clerk_Semaphore,1,NULL);
        Customer_Number++;
        Customer_Counter[i]++;
    }

    return 0;
}

int main()
{
    HANDLE Clerk_Handle[TOTAL_CLERK];
    INT Clerk_Numbers[TOTAL_CLERK];
    srand(GetTickCount());
    Clerk_Semaphore = CreateSemaphore(NULL,TOTAL_CLERK,TOTAL_CLERK,NULL);
    ZeroMemory(Customer_Counter,sizeof(Customer_Counter));

    for(int i = 0; i < TOTAL_CLERK; i++)
    {
        Clerk_Numbers[i] = i;
        Clerk_Handle[i] = (HANDLE)_beginthreadex(NULL,0,Clerk,&Clerk_Numbers[i],CREATE_SUSPENDED,NULL);
    }

    printf("Stuffs are ready\n");

    for(int i = 0; i < TOTAL_CLERK; i++)
    {
        ResumeThread(Clerk_Handle[i]);
    }

    WaitForMultipleObjects(TOTAL_CLERK,Clerk_Handle,TRUE,INFINITE);

    for(int i = 0; i < MAX_CUSTOMER; i++)
    {
        printf("Customer %2d processed by %d Clerks\n",i,Customer_Counter[i]);
    }

    CloseHandle(Clerk_Semaphore);
    system("pause");
    return 0;
}
