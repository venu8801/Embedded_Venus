#include<stdio.h>
void main()
{
	char *ptr1 = 0x5000;
	char *ptr2 = 0x5008;

	printf("%p\n",(ptr2 - ptr1));
	short int *ptr3 = 0x5000;
	short int *ptr4 = 0x5008;

	printf("%p\n",(ptr4 - ptr3));


}

