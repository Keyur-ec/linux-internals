#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

void main(){
	int fd;
	char* ch;

	struct stat file_info;
	fd = open("hello.txt", O_CREAT | O_RDWR, 777);
	write(fd, "hello from linux!", 17);

	fstat(fd, &file_info);
	printf("file size is %d\n", file_info.st_size);

	ch = mmap(0, file_info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	perror("mmap");
	for (int i=0; i<=16; i++)
		printf("%s\n", ch);

	munmap(ch, file_info.st_size);
	close(fd);
}
