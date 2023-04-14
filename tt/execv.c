#include <stdio.h>
#include <stdlib.h>

void main(){
	char *args[3];
	printf("i am going to exec an 'ls' program in current process\n");

	args[0] = "ls";
	args[1] = "-l";
	args[3] = NULL;

	execv("/bin/ls", args);

	printf("i have run an execv sys call");
}
