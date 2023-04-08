#include <stdio.h>

int main(int argc, char** argv){
	int i;
	int x[] = {12, 22, 33, 44};

	for(i=0; i<4; i++) 
		printf("value of x=%d\n", x[i]);
	return 0;
}
