#include <stdio.h>
#include <signal.h>

void check_blocked_signals(){
	int i, result;
	sigset_t s;
	sigprocmask(SIG_BLOCK, NULL, &s);

	for(i=1;i<=64;i++){
		result = sigismember(&s, i);

		if(result){
			if(i < 10) printf("signal 0%d is blocked    \t", i);
			else       printf("signal %d is blocked    \t", i);
		}
		else{
		 	if(i < 10) printf("signal 0%d is not blocked\t", i);
			else       printf("signal %d is not blocked\t", i);
		}

		if(i % 4 == 0) printf("\n");
	}
}

void main(){
	sigset_t s_set;
	sigfillset(&s_set);
	sigprocmask(SIG_BLOCK | SIG_SETMASK, &s_set, NULL);
	check_blocked_signals();
}
