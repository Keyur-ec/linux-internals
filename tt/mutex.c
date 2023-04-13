#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int iAmGlobal = 0;
pthread_mutex_t my_mutex;

void* thread1(void* ptr){
	pthread_mutex_lock(&my_mutex);
	for(int i=0; i<100000; i++)
		iAmGlobal++;
	pthread_mutex_unlock(&my_mutex);
	printf("printing from %s\n", __func__);
}

void* thread2(void* ptr){
        pthread_mutex_lock(&my_mutex);
        for(int i=0; i<100000; i++)
                iAmGlobal++;
        pthread_mutex_unlock(&my_mutex);
	printf("printing from %s\n", __func__);
}

void main(){
	pthread_t tid1;	
	pthread_t tid2;	

	pthread_mutex_init(&my_mutex, NULL);

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("final count is : %d\n", iAmGlobal);
}
