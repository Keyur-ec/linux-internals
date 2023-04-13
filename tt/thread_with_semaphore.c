#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int iAmGlobal = 0;
sem_t my_sem;

void* thread1(void* ptr){
	sem_wait(&my_sem);
	for(int i=0; i<100000; i++)
		iAmGlobal++;
	sem_post(&my_sem);
	printf("printing from %s\n", __func__);
}

void* thread2(void* ptr){
        sem_wait(&my_sem);
        for(int i=0; i<100000; i++)
                iAmGlobal++;
        sem_post(&my_sem);
	printf("printing from %s\n", __func__);
}

void main(){
	pthread_t tid1;	
	pthread_t tid2;	

	sem_init(&my_sem, 0, 1);

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("final count is : %d\n", iAmGlobal);
}
