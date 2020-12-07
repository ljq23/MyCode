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
	int sock = socket(AF_INET,SOCK_STREAM,0);

	//向服务器（特定的IP和端口）发起请求
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
	serv_addr.sin_family = AF_INET;  //使用IPv4地址
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
	serv_addr.sin_port = htons(1234);  //端口
	// 开始进行 三次握手 连接
	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//读取服务器传回的数据
	char buffer[BUF_SIZE];
	printf("Input a string: ");
	scanf("%s", buffer);
	send(sock,buffer,sizeof(buffer)-1,0);
	// 接受服务器传回数据
	char bufRecv[BUF_SIZE];
	recv(sock, bufRecv, BUF_SIZE, 0);

	// 输出接受到的数据
	printf("Message from server: %s\n", bufRecv);

	//关闭套接字
	close(sock);

	return 0;
}
