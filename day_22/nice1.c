#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void main(){
	int ret, i, count=0;

	errno = 0;
	ret = nice(1);

	if(ret == -1 && errno != 0) perror("nice");
	else printf("nice value is %d\n", ret);

	while(1){
		printf("process with nice value %d and count = %d\n", ret, count);
		for(i=0; i<90000000; i++) __asm__("nop");
		count++;
	}
}
