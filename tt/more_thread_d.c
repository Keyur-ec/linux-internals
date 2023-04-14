#include <stdio.h>
#include <pthread.h>

int count = 0;

void* thread1(void* arg){
	for(int i=0; i<100000; i++) count++;
}

void* thread2(void* arg){
	for(int i=0; i<100000; i++) count++;
}

void main(){
	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	printf("final count is %d\n", count);
}
