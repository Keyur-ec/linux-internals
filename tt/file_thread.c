#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>

void* th_fn(void* p);
int fd;

void main(){
	pthread_t t1, t2;
	
	fd = open("temp.txt", O_RDONLY);
	printf("file opend with fd: %d\n", fd);

	pthread_create(&t1, NULL, th_fn, "thread one");
	pthread_create(&t2, NULL, th_fn, "thread two");

	pthread_join(t1 ,NULL);
	pthread_join(t2 ,NULL);

	close(fd);
}

void* th_fn(void* p){
	char* str, buff[100];
	int n, pid;

	str = (char*)p;
	pid = getpid();

	printf("%s: \t started now: \t for process %d \n\n", str, pid);

	do{
		n = read(fd, buff, 100);
		printf("%s: \t read: \t %d \n\n", str, pid);
		printf("\n-----------------------------\n");

		write(1, buff, n);
	
		printf("\n-----------------------------\n");
		sleep(3);
	}while(n);

	printf("%s: \t finished: \t for process %d \n\n", str, pid);
}
