#include <stdio.h>

void main(){
	int p[2];
	pipe(p);
	printf("read end of pipe = %d\t write end of pipe = %d\n", p[0], p[1]);
	
	if(fork()){
		char s[20];
		printf("i am in the perent : enter a data :\n");
		scanf("%s", s);
		write(p[1], s, strlen(s));
	}

	else{
		char buffer[20];
		printf("i am in the child...\n");
		read(p[0], buffer, sizeof(buffer));
		printf("data got from perent process : %s\n", buffer);
	}
}
