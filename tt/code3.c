#include <stdio.h>

int main(int argc, char** argv){
	printf("%d\n", argc);
	
	for(int i=0; i<argc; i++) printf("%s\n", argv[i]);

	char buffer[] = "linux";
	printf("message: %s\n", buffer);

	return 0;
}
