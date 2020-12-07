#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main()
{
	//先输入文件名，检查文件是否创建成功
	char fileName[BUF_SIZE];
	printf("Input filename to save: ");
	scanf("%s",fileName);
	FILE* fp = fopen(fileName,"wb");
	if(fp == NULL)
	{
		printf("Cannot open the file\n");
		return -1;
	}

	//创建套接字
	int sock = socket(AF_INET,SOCK_STREAM,0);

	//向服务器（特定的IP和端口）发起请求
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
	serv_addr.sin_family = AF_INET;  //使用IPv4地址
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
	serv_addr.sin_port = htons(1234);  //端口
	// 开始进行 三次握手 连接
	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//循环接受数据，直到文件传输完毕
	char buffer[BUF_SIZE]; // 文件缓存区
	int nCount;
	bool flag = false;
	while((nCount=recv(sock,buffer,BUF_SIZE,0))>0)
	{
		fwrite(buffer,nCount,1,fp);
		printf("%d Bytes\n", nCount);
		flag = true;
	}
	if(flag)
		printf("File transfer success!\n");
	else 
		printf("Fail\n");
	
	fclose(fp);
	//关闭套接字
	close(sock);

	return 0;
}
