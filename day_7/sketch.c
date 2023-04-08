#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	int fd, len;
	char wr_payload[50] = "hello from file!";
	char rd_payload[50];

	fd = open("test.txt", O_CREAT | O_RDWR, 777);
	len = write(fd, wr_payload, 50);
	printf("number of bytes write to the file is: %d\n", len);

	lseek(fd, 0, SEEK_SET);

	read(fd, rd_payload, len);
	printf("readed data from file is: %s\n", rd_payload);

	close(fd);
}
