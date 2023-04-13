#include <stdio.h>
#include <pthread.h>

#define NUM_OF_THREAD 3
int i = 0;

void* myFunc(void* ptr){
	i++;
	int result = 0;
	result = result + i * 1000;
	printf("result = %d\n", result);
	sleep(1);
	printf("job done!\n");
}

void main(){
	pthread_t thread[NUM_OF_THREAD];
	pthread_attr_t attr;

	int rc, t, status, detach_state;

	pthread_attr_getdetachstate(&attr, &detach_state);
	printf("detach state : %d\n", (int*)detach_state);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	for(t=NUM_OF_THREAD; t>0; t--){
		printf("creating thread %d\n", t);
		rc = pthread_create(&thread[t], &attr, myFunc, NULL);

		if(rc){
			printf("error return code from pthread_create() id %d\n", rc);
			exit(0);
		}
	}

	pthread_attr_getdetachstate(&attr, &detach_state);
	printf("detach state : %d\n", (int*)detach_state);

	pthread_attr_destroy(&attr);

	printf("exiting from main...\n");

	//for(t=NUM_OF_THREAD; t>0; i--)
	//	rc = pthread_join(thread[t], NULL);

	pthread_exit(0);
}
