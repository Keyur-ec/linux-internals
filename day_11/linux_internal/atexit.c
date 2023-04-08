#include <stdio.h>
#include <unistd.h>

void fn1(){
	printf("i am from %s\n", __func__);
}

void fn2(){
        printf("i am from %s\n", __func__);
}

void fn3(){
        printf("i am from %s\n", __func__);
}

void main(){
	printf("i am from %s\n", __func__);
	atexit(fn1);
	atexit(fn2);
	atexit(fn3);
	printf("exiting from %s...\n", __func__);
}
