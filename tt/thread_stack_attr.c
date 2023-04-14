#include <stdio.h>
#include <pthread.h>

void main(){
	pthread_attr_t stack_attr;
	pthread_t tid;

	int ret;
	void* stackbase;
	//int size = PTHREAD_STACK_MIN + PTHREAD_STACK_MIN;
	int size = PTHREAD_STACK_MIN * 2;
	size_t size1;

	stackbase = (void*)malloc(size);

	ret = pthread_attr_init(&stack_attr);
	ret = pthread_attr_getstacksize(&stack_attr, &size1);

	printf("default stack size : %lu\n", size1);
	printf("thread mnimum stack size : %lu\n", PTHREAD_STACK_MIN);

	ret = pthread_attr_setstacksize(&stack_attr, size);
	ret = pthread_attr_getstacksize(&stack_attr, &size1);

	printf("user stack size : %lu\n", size1);
}
