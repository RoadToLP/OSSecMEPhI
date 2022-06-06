#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <errno.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void handler(int fd){
	dprintf(fd, "Hello! I am example socket service!\nEverything you will send me will be mirrored.\nYou can start now\n");
	uint8_t msg[256];
	for (;msg[511] != 65;){
		memset(msg, 0, 256);
		int bread = recv(fd, msg, 512, 0);
		send(fd, msg, bread, 0);
	}
	
}


int main(){
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr, client;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(31337);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	const int enable = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)); 
	bind(sock, (struct sockaddr*)&addr, sizeof(addr));
	listen(sock, 5);
	int nsock = 0;
	int clientLen = sizeof(client);
	while ((nsock = accept(sock, (struct sockaddr*)&client, &clientLen)) != -1){
		signal(SIGCHLD, SIG_IGN);
		if (!fork()){
			handler(nsock);
			exit(0);
		}
	}
		
}
