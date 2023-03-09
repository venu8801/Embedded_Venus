struct example
{
	char x;
	char y;
	int n;
}__attribute__((packed)); // this line reduces the size of structure by completely avoiding holes 
#include<stdio.h>
void main()
{

	printf("size of structure is: %d\n", sizeof(struct example));
}

