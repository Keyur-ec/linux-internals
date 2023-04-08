#include <string.h>

void main(){
	char* buffer = "running main.c file from current directory\n";
	write(1, buffer, strlen(buffer));
	execl("./main","./main", "keyur panchal", 0);
	return;
}
