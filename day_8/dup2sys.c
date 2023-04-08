#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd1, fd_user;

	fd1 = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 777);
	
	printf("fd1 = %d\n", fd1);

	fd_user = dup2(fd1, 17);

	printf("fd_user = %d\n", fd_user);
	
	close(fd1);
	close(fd_user);
}
