#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
	for (int i = 0; i < 10; i++){
		pid_t pid = fork();
		if (pid < -1){
			fprintf(stderr, "Couldn't fork\n");
			exit(errno);
		}
		if (!pid) {
			printf("Printf from child. PID - %d, PPID - %d\n", getpid(), getppid());
			sleep(5);
			return 0;
		}
	}
	printf("Printf from parent. PID - %d\n", getpid());
	int status;
	waitpid(-1, &status, 0);
	
}
