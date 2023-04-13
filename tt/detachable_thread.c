#include <stdio.h>
#include <pthread.h>

#define NUM_OF_THREAD 2

void* task(void* ptr){
	for(unsigned long int i=1000000000; i>0; i--)
		__asm__("nop");
	printf("task finished from %s\n", __func__);
}

void main(){
	pthread_t th[NUM_OF_THREAD];
	int i;

	for(i=NUM_OF_THREAD; i>0; i--){
		if(pthread_create(&th[i], NULL, task, NULL) != 0) perror("failed to create!\n");
		pthread_detach(th[i]);
	}

	for(i=0; i<NUM_OF_THREAD; i++){
		if(pthread_join(th[i], NULL) != 0) perror("failed to join!\n");
	}

	pthread_exit(0);
}
