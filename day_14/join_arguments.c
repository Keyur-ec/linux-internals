#include <stdio.h>
#include <pthread.h>

void* thread1(void* ptr){
	printf("thread 1 exiting\n");
	printf("thread id = %lu\n", pthread_self());
	pthread_exit((void*)1);
}

void* thread2(void* ptr){
	printf("thread 2 exiting\n");
	printf("thread id = %lu\n", pthread_self());
	pthread_exit((void*)2);
}

void main(){
	int err;
	pthread_t tid1, tid2;

	void* tret;

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1, &tret);
	printf("thread 1 exit code %d\n", (int)tret);

	pthread_join(tid2, &tret);
	printf("thread 2 exit code %d\n", (int)tret);
	
	exit(0);
}
