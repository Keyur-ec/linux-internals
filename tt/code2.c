#include <stdio.h>

void myprint(char* msg){
	if(msg != NULL) printf("msg: %s\n", msg);
}

int main(int argc, char** argv){
	char buffer[] = "linux";
	myprint(buffer);

	return 0;
}
