#include<stdio.h>
int main()
{
	register int  x = 10;
	// x gets stored in register memory if there is free space in register 
	// memory
	printf("x = %d\n",x);

}


