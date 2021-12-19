#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char** argv, char** envp){
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <num>\n", argv[0]);
		return EINVAL;
	}
	for (int i = 0; *envp && i < atoi(argv[1]) && (i++ | 1); envp++) printf("%s\n", envp[i]);
}
