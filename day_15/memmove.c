#include <stdio.h>

void main(){
	const char msg[20] = "hello from linux!";
 	const char msg1[20] = "hello from keyur!";

	memmove(msg1, msg, 12);
	printf("message is %s\n", msg);
	printf("message is %s\n", msg1);
	return; 
}
