#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <bits/types.h>
#include <sys/types.h>
#include <pthread.h>

static pthread_spinlock_t slock;

void* spinLockThread(void* ptr){
	int rc;
	int count = 0;

	printf("enterd thread %d, getting spin lock\n", (int*)ptr);
	rc = pthread_spin_lock(&slock);
	
	printf("%d thread unlock the spin lock.... after 5 second\n", (int*)ptr);
	rc = pthread_spin_unlock(&slock);

	printf("%d thread complite\n", (int*)ptr);
	return NULL;
}

void main(){
	int rc = 0;
	pthread_t thread, thread1;

	if(pthread_spin_init(&slock, PTHREAD_PROCESS_PRIVATE) != 0) perror("init");
	printf("main, get spin lock!\n");
	rc = pthread_spin_lock(&slock);

	printf("main, create the spin lock thread\n");
	rc = pthread_create(&thread, NULL, spinLockThread, (int*)1);

	printf("main, wait a bit holding the spin lock\n");
	sleep(5);

	printf("main, now unlock the spin lock\n");
	rc = pthread_spin_unlock(&slock);

	if(rc == 0) printf("main thread successfully unlocked\n");
	else printf("failed to unlock main thread");

	printf("main, wait for the thread to end\n");
	rc = pthread_join(thread, NULL);
	rc = pthread_spin_destroy(&slock);
	printf("main completed\n");
}
