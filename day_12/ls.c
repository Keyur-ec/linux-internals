#include <stdio.h>
#include <stdlib.h>

void main(){
	int ret;

	printf("i am going to exec an 'ls' program\n");
	ret = execl("/bin/ls", "ls", "-l", 0);
	printf("i ececuted ls program %d\n", ret);
	printf("i ececuted ls program %d\n", ret);
	printf("i ececuted ls program %d\n", ret);
}
