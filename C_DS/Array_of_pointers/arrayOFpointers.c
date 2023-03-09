#include<stdio.h>
void main()
{
	int *ptr[4]; // array of pointers
	int i;	
	int x = 10;
	int y = 20;
	int z = 30;
	int a = 40;

	ptr[0] = &x;
	ptr[1] = &y;
	ptr[2] = &z;
	ptr[3] = &a;

	for(i = 0; i < 4; i++)
	{	
		printf("Array of pointer's Address:%p \n",(ptr + i));

		printf(" Variable's Address:%p \n",ptr[i]);
		printf(" Variable's Data:%d \n",*ptr[i]);
		//printf("Address: %p \n",(*ptr + i) );
		//printf("Data :%d \n",*(*ptr + i));



	}
}

