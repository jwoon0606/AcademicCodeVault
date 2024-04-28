#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TEXT 256
#define MAX_LEN 128

int main(){
	char *argv[MAX_LEN];
	int argc = 0;
	char cmd[MAX_TEXT] = "";
	
	printf("Welcome to MyShell!\n");
	while(1){
		printf("$ ");
		fgets(cmd, MAX_TEXT, stdin);
		int len = strlen(cmd) - 1;
		cmd[len] = 0;

		argc = 0;

		for(int i=0; i<len; i++){
			for(; i<len && isspace(cmd[i]); i++);
			if(i == len)
				break;

			int j = 0;
			for(j=i+1; j<len && !isspace(cmd[j]); j++);
			cmd[j] = 0;

			argv[argc] = &cmd[i];

			if(++argc >= len)
				break;

			i = j;
		}
		argv[argc] = 0;
		
		// cmd
		printf("cmd = \"%s\"\n",cmd);

		// exit
		if(strcmp(cmd,"exit") == 0){
			break;
		}

		// argc, argv
		printf("argc = %d\n",argc);
		for(int i=0; i<argc; i++)
			printf("\targv[%d] = \"%s\"\n",i,argv[i]);
		printf("\targv[%d] = \"%s\"\n",argc,argv[argc]);

		// cd
		if(strcmp(argv[0],"cd") == 0){
			if(chdir(argv[1]) == -1)
				perror("cd");
		}

		// else
		else if(strcmp(argv[0],"") != 0){
			pid_t pid = fork();
			if(pid > 0)
				wait(0);
			else if(!pid){
				if(execvp(argv[0],argv) == -1)
					perror(argv[0]);
			}
			else if(pid < 0)
				perror("fork");
		}
	}
	printf("Bye!\n");

	return 0;
}
