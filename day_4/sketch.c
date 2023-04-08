#include <stdio.h>
#include <stdlib.h>

void buggy(int*p ){
	p[0] = 10;
	free(p);
}

int main(int argc, char** argv){
	int* ptr;
	ptr = (int*)malloc(4);
	buggy(ptr);
	free(ptr);
	return 0;
}
