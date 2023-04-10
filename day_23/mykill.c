#include <stdio.h>
#include <signal.h>
#include <string.h>

void main(int argc, char** argv){
	if(argc != 3){
	       printf("not enough arguments!\n"); 
	       return;
	}

	kill(atoi(argv[2]), atoi(argv[1]));
	perror("sig_res:");
}
