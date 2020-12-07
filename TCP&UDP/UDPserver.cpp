#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

int main(){
	//创建套接字
	// SOCK_STREAN  tcp
	// SOCK_DGRAM	udp
	int serv_sock = socket(AF_INET, SOCK_DGRAM, 0);

	//将套接字和IP、端口绑定
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
	serv_addr.sin_family = AF_INET;  //使用IPv4地址
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //自动获取本机的IP地址
	serv_addr.sin_port = htons(1234);  //端口
	// 绑定 ip 与 端口
	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//接收客户端请求
	struct sockaddr_in clnt_addr; //客户端地址信息
	socklen_t clnt_addr_size = sizeof(clnt_addr);

	char buffer[BUF_SIZE]; // 缓存区
	while(1)
	{
		int strLen = recvfrom(serv_sock,buffer,BUF_SIZE,0,(struct sockaddr*)&clnt_addr, &clnt_addr_size);
		buffer[strLen] = 0;
		printf("Get message: %s\n", buffer);
		sendto(serv_sock, buffer, strLen, 0, (struct sockaddr*)&clnt_addr, clnt_addr_size);
		if(buffer[0]=='e'&&buffer[1]=='n'&&buffer[2]=='d') break;
	}

	//关闭套接字
	close(serv_sock);

	return 0;
}
