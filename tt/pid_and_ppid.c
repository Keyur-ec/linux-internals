#include <stdio.h>
#include <unistd.h>

void main(){
	printf("process pid is %d\n", getpid());
	printf("process ppid is %d\n", getppid());
	while(1);
}
