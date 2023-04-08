#include <stdio.h>

void main(){
	const char msg[] = "hello from linux";
	const char msg1[] = "hello from keyur";

	int ret = memcmp(msg, msg1, 17);
	printf("diffrence is %d\n", ret);

	if(ret > 0) printf("buffer 1 is grater that buffer 2\n");	
	else if(ret < 0) printf("buffer 1 is less that buffer 2\n");	
	else printf("both buffer 1 and buffer 2 is same\n");

	return; 
}
