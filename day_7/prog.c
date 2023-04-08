#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv){
	int fd = open("test.txt", O_CREAT|O_RDONLY);
	char data[1000];
	
	if(fd == -1) printf("fail to create file!");
	
	read(fd, data, 1000);
	if(data[0] == '\0') printf("file is empty! nothig to read!");
	
	printf("%s\n", data);
	close(fd);

	return 0;
}
