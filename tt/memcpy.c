#include <stdio.h>

void main(){
	const char msg[20] = "hello from linux!";
 	const char msg1[20];
	memcpy(msg1, msg, 17);
	printf("message is %s\n", msg);
	printf("message is %s\n", msg1);
	return; 
}
