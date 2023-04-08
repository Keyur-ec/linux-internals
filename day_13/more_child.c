#include <stdio.h>
#include <sys/wait.h>

void main(){

	pid_t chpid1, chpid2, child1, child2;
	int ii, stat;

	printf("i am process my process id is %d\n", getpid());
	printf("i am crating two child processes & make them run some code\n");

	child1 = fork();

	if(child1 == 0){
		printf("i am first child, my pid is %d\n", getpid());
		printf("i am tired, sleeping for 10 sec...\n");\
		sleep(10);
		exit(0);
	}

	child2 = fork();

	if(child2 == 0){
		printf("i am second child, my pid is %d\n", getpid());
		printf("i am tired, sleeping for 5 sec...\n");
		sleep(5);
		exit(0);
	}

	printf("i am perent, my childeren are working & sleeping. i wait for them\n");

	chpid2 = waitpid(child2, &stat, 0);
		printf("my first child terminated with status %d\n", WEXITSTATUS(stat));
		printf("terminated child2 pid from wait = %d\n", chpid2);

	chpid1 = waitpid(child1, &stat, 0);
		printf("my second child terminated with status %d\n", WEXITSTATUS(stat));
		printf("my second child terminated with status %d\n", WEXITSTATUS(stat));
		printf("terminated child1 pid from wait= %d\n", chpid1);

	printf("both children got terminated, now i will do the same\n");
}
