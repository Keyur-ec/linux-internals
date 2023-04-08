#include <stdio.h>
#include <unistd.h>

void main(){
	printf("this is first printf!\n");
	fork();
	printf("this is second printf!\n");
	while(1);
}
