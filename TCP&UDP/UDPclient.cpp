#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main()
{
	//创建套接字
	int sock = socket(AF_INET,SOCK_DGRAM,0);

	//向服务器（特定的IP和端口）发起请求
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
	serv_addr.sin_family = AF_INET;  //使用IPv4地址
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
//	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //自动获取 本机 的ip地址
	serv_addr.sin_port = htons(1234);  //端口


	// 不断获取用户c输入并发送给服务器，然后接受服务器数据
	sockaddr fromAddr;
	socklen_t addrLen = sizeof(fromAddr);
	while(1)
	{
		char buffer[BUF_SIZE];
		printf("Input a string: ");
		scanf("%s", buffer);
		sendto(sock,buffer,strlen(buffer),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
		int strLen = recvfrom(sock,buffer,BUF_SIZE,0,&fromAddr,&addrLen);
		buffer[strLen] = 0;//字符串结尾
		printf("Message from server: %s\n", buffer);
		if(buffer[0]=='e'&&buffer[1]=='n'&&buffer[2]=='d') break;
	}

	//关闭套接字
	close(sock);

	return 0;
}
