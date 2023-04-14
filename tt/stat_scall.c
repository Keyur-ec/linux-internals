#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void main(){
	struct stat st;
	int fd;

	stat("hello.txt", &st);
	printf("file size = %lu\n", (st.st_size));
	printf("file inode = %lu\n", (st.st_ino));
	printf("size disc of blocks = %lu\n", (st.st_blksize));
	close(fd);
}
