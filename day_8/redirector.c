#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char buffer[100] = "this string is dumped into dump.txt file";
	int print_fd = 1;
	int dump_fd = open("dump.txt", O_WRONLY | O_CREAT, 777);
	
	dup2(dump_fd, print_fd);
	write(print_fd, buffer, strlen(buffer));
	
	close(dump_fd);

	return 0;
}
