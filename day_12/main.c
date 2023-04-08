#include <string.h>

void main(int argc, char** argv){
	if(argc == 2){
		write(1, argv[1], strlen(argv[1]));
		write(1, "\n", 1);
	}
	return;
}
