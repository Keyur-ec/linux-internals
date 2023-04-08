#include <stdio.h>

void main(){
	const char msg[] = "hello from linux";
	const char ch = '#';
	//memset(msg, ch, 3);
	memset(msg+2, ch, 3);
	printf("output after memset is %s\n", msg);
	
	return; 
}
