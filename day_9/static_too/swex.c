#include<stdio.h>

void main(){
	int number;
	
	printf("enter a number: ");
	scanf("%d", &number);

	switch(number){
		case 1:
			printf("one\n");
			break;
		case 2: 
			printf("two\n");
			break;
		case 3:
			printf("three\n");

		default:
			printf("this is not a number!\n");
			break;
	}
}
