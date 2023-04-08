#include <stdio.h>

int main(int argc, char** argv){
	int number;

	do{
		printf("enter a number: ");
		scanf("%d", &number);
	}while(number < 0);

	int fact = 1;
	for(int i=1; i<=number; i++)
		fact = fact * i;
	printf("%d! = %d\n", number, fact);
	
	return 0;
}
