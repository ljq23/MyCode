#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

int main(){
	// 文件检查
//	char fileName[] = "test.cpp";
	char fileName[BUF_SIZE];
	printf("Please input a fileName: ");
	scanf("%s",fileName);
	FILE * fp = fopen(fileName,"rb");
	if(fp == NULL)
	{
		printf("file is not exit\n");
		return -1;
	}

	//创建套接字
        int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//将套接字和IP、端口绑定
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
	serv_addr.sin_family = AF_INET;  //使用IPv4地址
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
	serv_addr.sin_port = htons(1234);  //端口
	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//进入监听状态，等待用户发起请求
	listen(serv_sock, 20);

	printf("Waiting.................\n");
	//接收客户端请求
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

	// 循环发送数据，直到文件结尾
	char buffer[BUF_SIZE];
	int nCount;
	while((nCount=fread(buffer,1,BUF_SIZE,fp))>0)
	{
		write(clnt_sock, buffer, nCount);
		printf("%d bytes to client\n", nCount);
	}
	
	shutdown(clnt_sock, SHUT_WR);
	// SHUT_RD 断开输入流
	// SHUT_WR 断开输出流
	// SHUT_RDWR 同时断开IO流
	
	recv(clnt_sock, buffer, BUF_SIZE, 0);

	fclose(fp);
	//关闭套接字
	close(clnt_sock);
	close(serv_sock);

	return 0;
}
