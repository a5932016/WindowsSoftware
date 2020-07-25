// Server.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib,"WS2_32")

int _cdecl main()
{
	// 初始化
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(827);
	sockaddr.sin_addr.S_un.S_addr = INADDR_ANY;

	// 綁定通訊阜
	bind(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));
	listen(s, 1);
	SOCKADDR clientAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clientSock;

	// 取得與Client聯繫的socket
	clientSock = accept(s, (SOCKADDR*)&clientAddr, &nSize);
	char inbuf[1024];

	// 接收資料
	recv(clientSock, inbuf, sizeof(inbuf), NULL);
	printf("Receive: %s\r\n", inbuf);
	char outbuf[] = "Hello Polaris\r\n";

	// 傳送資料
	send(clientSock, outbuf, strlen(outbuf) + sizeof(char), NULL);

	// 關閉與Clinet的聯繫
	shutdown(clientSock, 0);
	closesocket(clientSock);

	// 關閉Server
	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;
}
