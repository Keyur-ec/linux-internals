#include <stdio.h>
#include <pthread.h>

pthread_t tid;

void* thread1(void* arg){
	sleep(1);
	printf("hello from linux!\n");
	return NULL;
}

void main(){
	int ret = pthread_create(&tid, NULL, thread1, NULL);

	if(ret) printf("thread is not cerated!\n");
	else printf("thread is succesfully created\n");
	
	pthread_join(tid, NULL);	
}
