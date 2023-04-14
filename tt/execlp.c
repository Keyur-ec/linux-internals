#include <stdio.h>

void main(){
	printf("i am going to exec an ls process in current process\n");
	execlp("ls", "ls", 0);
	printf("i excuted 'ls' process\n");
}
