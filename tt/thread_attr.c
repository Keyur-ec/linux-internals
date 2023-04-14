#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// in this case we set stack attribute

void* thread(void* ptr){
	sleep(2);
	return 0;
}

void main(){
	pthread_attr_t myattr;
	pthread_t tid;
	void* stack;
	size_t size;
	int err;

	size_t my_stack_size = 0x300000;
	void* my_stack;

	pthread_attr_init(&myattr);

	pthread_attr_getstacksize(&myattr, &size);
	pthread_attr_getstackaddr(&myattr, &stack);
	printf("default addr = %08x \t defalut size = %d\n", stack, size);

	my_stack = (void*)malloc(my_stack_size);
	pthread_attr_setstack(&myattr, my_stack, my_stack_size);

	pthread_create(&tid, &myattr, thread, NULL);

	pthread_attr_getstack(&myattr, &stack, &size);
	printf("newly defined stack : addr = %08x and size = %d\n", stack, size);

	sleep(3);

	pthread_attr_destroy(&myattr);
}
