#include <stdio.h>
#include <stdlib.h>

int buggy(){
	int* int_ptr;
	int i;
	
	int_ptr = (int*)malloc(sizeof(int)*4);
        char* char_ptr = malloc(sizeof(char)*4);
	
	*char_ptr = 'a';
	char_ptr++;
	*char_ptr = 'b';
	char_ptr++;
	*char_ptr = 'c';
	char_ptr++;
	*char_ptr = 'd';	

	printf("%c : char\n", (*char_ptr));
	char_ptr--;
	printf("%c : char\n", (*char_ptr));
	char_ptr--;
	printf("%c : char\n", (*char_ptr));
	char_ptr--;
	printf("%c : char\n", (*char_ptr));

	for(i=0;i<10;i++){
		*int_ptr = 100;
		printf("value at ptr int_ptr = %d\n", (*int_ptr));
		int_ptr++;
	}
}

int main(int argc, char** argv){
	buggy();
	return 0;
}
