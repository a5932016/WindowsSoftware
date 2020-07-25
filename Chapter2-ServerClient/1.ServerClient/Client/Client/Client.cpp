// Client.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib,"WS2_32")

int _cdecl main(void)
{
	// 初始化
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 取得伺服器位置
	sockaddr_in sockAddr;
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(827);
	inet_pton(AF_INET, "127.0.0.1", (void*)&sockAddr.sin_addr.S_un.S_addr);

	// 連接 Server
	connect(s, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

	// 傳送訊息
	char szMessage[] = "Give me the money.";
	send(s, szMessage, strlen(szMessage) + sizeof(char), 0);

	// 接收資料
	char szBuffer[MAXBYTE] = { 0 };
	recv(s, szBuffer, MAXBYTE, NULL);
	printf("szBuffer: %s \r\n", szBuffer);

	// 關閉與連線
	shutdown(s, 0);
	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;
}
