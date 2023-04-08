#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd1, fd2;

	fd1 = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);
	
	printf("fd1 = %d\n", fd1);

	fd2 = dup(fd1);

	printf("fd2_dup of fd1 = %d\n", fd2);
	
	close(fd1);
	close(fd2);
}
