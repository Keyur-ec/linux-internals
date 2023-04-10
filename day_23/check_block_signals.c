#include <stdio.h>
#include <signal.h>

void check_blocked_sig(){
	int i, result;
	sigset_t s;

	sigprocmask(SIG_BLOCK, NULL, &s);

	for(i=1; i<10; i++){
		result = sigismember(&s, i);

		if(result) printf("signal %d is blocked\n", i);
		else printf("signal %d is not blocked\n", i);
	}
}

void main(){
	sigset_t s_set;
	sigemptyset(&s_set);

	sigaddset(&s_set, 1);
	sigaddset(&s_set, 4);
	sigaddset(&s_set, 9);
	
	sigprocmask(SIG_BLOCK | SIG_SETMASK, &s_set, NULL);

	check_blocked_sig();
	sigprocmask(SIG_UNBLOCK, &s_set, NULL);	
	check_blocked_sig();
}
