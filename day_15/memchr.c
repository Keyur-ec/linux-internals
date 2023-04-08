#include <stdio.h>

void main(){
	const char msg[] = "hello from linux";
	const char ch = 'f';
	char* ret = memchr(msg, ch, 17);
	printf("string after char '%c' at %s\n", ch, ret+1);
	
	return; 
}
