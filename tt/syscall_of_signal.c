#include <stdio.h>
#include <signal.h>

void sighand(){
	printf("i am in %s\n", __func__);
}

void main(){
	sigset_t s_set;
	signal(1, sighand);

	sigemptyset(&s_set);
	
	sigaddset(&s_set, 1);
	perror("sig1");

	sigaddset(&s_set, 4);
	perror("sig4");

	sigprocmask(SIG_BLOCK, &s_set, NULL); /* SIG_BLOCK: set of signals pointed by s_set are blocked 
					      for current process */
	perror("sigmask");
	
	printf("pid of the current process is %d\n", getpid());
	printf("send me signal one and see the effect now\n");

	getchar();
	getchar();

	sigprocmask(SIG_UNBLOCK, &s_set, NULL);
	printf("now signals are unblocked\n");

	while(1);
}
