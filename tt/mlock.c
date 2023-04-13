#include <stdio.h>
#include <unistd.h>

void main(){
	size_t i;
	const int alloc_size = 1024 * 1024;
	char* memory = malloc(alloc_size);
	mlock(memory, alloc_size);

	for(i=0; i<alloc_size; i++)
		memory[i] = 'K';

	printf("allocated memory initialized with %s\n", memory);
	munlock(memory, alloc_size);
}
