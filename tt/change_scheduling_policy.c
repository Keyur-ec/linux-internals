// NOTE : use sudouser to run this code otherwise it will give an error 

#include <stdio.h>
#include <sched.h>

void checkPolicy(int policy){
	switch(policy){
		case SCHED_OTHER:
			printf("policy is normal\n");
			break;
		case SCHED_RR:
			printf("policy is round robin\n");
			break;
		case SCHED_FIFO:
			printf("policy is first in first out\n");
			break;
		case -1:
			perror("shed_getschdeluer");
			break;
		default:
			fprintf(stderr, "unknown policy!\n");
	}
}

void main(){
	int policy;
	printf("my pid is %d\n", getpid());	

	policy = sched_getscheduler(0);
	checkPolicy(policy);

	write(1, "press any key to change policy...\n", 50);
	getc(stdin);
	
	struct sched_param sp = {.sched_priority = 1};
	int ret;

	ret = sched_setscheduler(0, SCHED_RR, &sp);
	if(ret == -1){
		perror("sched_setscheduler");
		return;
	}

	policy = sched_getscheduler(0);
	checkPolicy(policy);
}
