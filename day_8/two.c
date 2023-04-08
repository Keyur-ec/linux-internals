#include <stdio.h>
#include <fcntl.h>

void main(){
	int fd = open("hello.txt", O_RDONLY);
	printf("%d\n", fd);
	while(1);
}
