#include<stdio.h>
void main()
{
	int a = 9;
	if(a = 5) // (a = 0) results in false condition executing else body 
		printf("a is five\n");
	else
		printf("a is not five\n");
	printf("The value of a is %d\n",a);
}

