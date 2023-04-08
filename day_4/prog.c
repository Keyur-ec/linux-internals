#include <stdio.h>
#include <stdlib.h>

void buggy(){
	int* int_ptr;
	int_ptr = (int*)malloc(sizeof(int));

	*int_ptr = 100;
	printf("value at ptr int_ptr: %d\n", (*int_ptr));
	free(int_ptr);
	*int_ptr = 99;
}

int main(int argc, char** argv){
	buggy();
	return 0;
}
