#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

void main(){
	pid_t pid;
	int sig_num;

	printf("pid of current process %d\n", getpid());
	printf("enter the pid of process for which the signal need to be sent: ");
	scanf("%d", &pid);
	printf("enter the signal that need to be sent: ");
	scanf("%d", &sig_num);

	perror("sig_res:");
}
