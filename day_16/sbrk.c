#include <stdio.h>
#include <unistd.h>

void main(){
	long int page_size = sysconf(_SC_PAGESIZE);
	printf("my page size : %ld\n", page_size);

	void* mem_ptr = sbrk(0);

	printf("program break point address : %p\n", mem_ptr);
	printf("sizeof char : %lu\n", sizeof(char));

	mem_ptr = ((char*) mem_ptr + 1);
	printf("mem_ptr : %p\n", mem_ptr);
	brk(mem_ptr);
	void* mem_ptr2 = sbrk(0);
	printf("program break point address : %p\n", mem_ptr2);
}
