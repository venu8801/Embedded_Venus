#include<stdio.h>
int main()
{
	int x = 10;

	int y = 20;

	const int * const ptr = &x;

	// *ptr = 15;
	//ptr = &y;	
	printf("%p\n",ptr);
	printf("%d\n",*ptr);

	return 0;
}
