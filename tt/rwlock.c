#include <stdio.h>
#include <pthread.h>

pthread_rwlock_t rwlock;

void* rdLockThread(void* ptr){
	int rc;
	int count = 0;

	printf("enterd %d thread, getting read lock\n", (int*)ptr);
	Retry:
	rc = pthread_rwlock_tryrdlock(&rwlock);

	printf("%d thread unlock the read lock\n", (int*)ptr);
	rc = pthread_rwlock_unlock(&rwlock);

	if(rc == 0) printf("successfully unlocked\n");
	else printf("failed to unlock\n");

	printf("secondary thread complete\n");
}

void main(){
	int rc = 0;
	pthread_t thread;

	if(pthread_rwlock_init(&rwlock, NULL) != 0) perror("init");
	printf("main, get the write lock\n");
	rc = pthread_rwlock_wrlock(&rwlock);

	printf("main, create the try read lock thread\n");
	rc = pthread_create(&thread, NULL, rdLockThread, (void*)1);

	printf("main, wait a bit holding the write lock\n");
	sleep(5);

	printf("main, now unlock the write lock\n");
	rc = pthread_rwlock_unlock(&rwlock);

	printf("main, wait for the thread to end\n");
	rc = pthread_join(thread, NULL);

	rc = pthread_rwlock_destroy(&rwlock);
	printf("main completed\n");
}
