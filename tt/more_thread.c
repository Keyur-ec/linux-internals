#include <stdio.h>
#include <pthread.h>

void* thread1(void* arg){
	int i;
	for(i=0; i<10; i++) printf("thd of control 1\n");
}

void* thread2(void* arg){
	int i;
	for(i=0;i<10; i++) printf("thd of control 2\n");
}

void main(){
	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}
