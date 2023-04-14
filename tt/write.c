#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main(){
	char* payload = "hello from file!";
	int fd = open("test.txt", O_WRONLY, 0777);
	int len = strlen(payload);
	write(fd, payload, len);
	close(fd);
}
