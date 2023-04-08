#include<stdio.h>

int global = 1;

void greet(char* name){
	printf("hello, %s\n", name);
	return;
}

int main(int argc, int** argv){
	printf("hello from linux!\n");
	greet("keyur");
	return 0;
}
