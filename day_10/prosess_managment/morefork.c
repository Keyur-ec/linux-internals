#include <stdio.h>
#include <unistd.h>

void main(){
	printf("hello from linux!");
	fork();
	fork();
	fork();
	printf("running...");
	while(1);
}
