#include <stdio.h>
#include <pthread.h>

void* greet(void* p){
	printf("hello from linux!\n");
	printf("waiting....\n");
	while(1);
}

void main(){
	pthread_t thread;

	int rc, t=0;

	printf("creating thread %d\n", t);
	rc = pthread_create(&thread, NULL, greet, NULL);
	printf("thread id : %u\n", thread);
	
	//pthread_join(thread, NULL);
	sleep(6);
	
	t = pthread_cancel(thread);
	if(!t)
		printf("canceld thread\n");
	printf("thread id : %u\n", thread);
}
