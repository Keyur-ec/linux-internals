#include <stdio.h>

void main(){
	int fds[2];
	int res, i;
	char buf1[20] = "hello from keyur...\n";
	char buf2[20] = "hello form linux...";
	char buf[40];

	res = pipe(fds);

	if(res == -1){
		perror("pipe");
		exit(1);
	}

	write(fds[1], buf1, 20);
	write(fds[1], buf2, 20);

	read(fds[0], buf, 40);

	printf("%s\n", buf);
}
