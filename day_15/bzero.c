#include <stdio.h>

void main(){
	const char msg[] = "hello from linux";
	//bzero(msg, 3);
	bzero(msg+2, 3);
	printf("output after memset is %s\n", msg);
	
	return; 
}
