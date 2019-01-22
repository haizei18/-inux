/*************************************************************************
	> File Name: client.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年09月23日 星期日 16时36分23秒
 ************************************************************************/
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>		
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include<iostream>
using namespace std;
#define MAX_SIZE 1000

int main(int argc, char *argv[]){
	int sock_client;
	char buffer[MAX_SIZE];
	struct sockaddr_in dest_addr;
	int port = atoi(argv[2]);
	char *host = argv[1];
    FILE *fp = fopen("./client.cpp","r");
	if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Socket");
		return -1;
	}
	
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(port);
	dest_addr.sin_addr.s_addr = inet_addr(host);
    printf("sss\n");
	if (connect(sock_client, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0){
		perror("Connect");
		return -1;
	}
    printf("iiii\n");
	while(1){
		scanf("%[^\n]s",buffer);
		getchar();
		send(sock_client, buffer, strlen(buffer), 0);
	}
	close(sock_client);

	
    return 0;
}
