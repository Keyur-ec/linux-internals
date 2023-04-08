#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 5

int main(int argc, char** argv){
	
	if(argc >= 3){
		int fd_rd = open(argv[1], O_RDONLY);
		int fd_wr = open(argv[2], O_CREAT | O_WRONLY, 0777);
		
		char buff[BUFFER_SIZE];

		while(1){
			int rint = read(fd_rd, buff, BUFFER_SIZE);
			write(fd_wr, buff, strlen(buff));
			printf("%d\n", rint);
			if(rint < BUFFER_SIZE) break;
		}

		close(fd_rd);
		close(fd_wr);
	}
	
	return 0;
}
