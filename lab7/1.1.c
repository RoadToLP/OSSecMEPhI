int main(int argc, char** argv, char** envp){
	int i;
	for (i = 0; *envp && (i++ | 1); envp++){}
	printf("Number of environment variables: %d\n", i);
}
