#include <stdio.h>
#include <sys/mman.h>

void main(){
	char* ptr = mmap(0, 20, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	strcpy(ptr, "linuxkernal");
	perror("mmap");
	printf("%s\n", ptr);
	munmap(ptr, 20);
}
