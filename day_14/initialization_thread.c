#include <stdio.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void myinit(){
	printf("booting up the system...\n");
	return;
}

void* thread(void* p){
	printf("now in thread %d\n", (int*)p);
	pthread_once(&once, myinit);
	printf("exiting from %d\n", (int*)p);
}

void main(){
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread, (void*)1);
	pthread_create(&tid2, NULL, thread, (void*)2);

	pthread_exit(NULL);
}
