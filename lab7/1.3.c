int main(int argc, char** argv, char** envp){
	for (int i = 0; *envp && i < 10 && (i++ | 1); envp++){
		printf("%s\n", envp[i]);
	}
}
