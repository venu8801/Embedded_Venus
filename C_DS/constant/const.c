#include<stdio.h>
int main()
{
	const char x = 10;

	printf("%d\n",x);

//	x = 45; 
//
//	if we use this it will result in compilation error
//	becuase we are modifying x const keyword informs compiler not to modify
	
	char *ptr;

	ptr = &x;

	*ptr = 11; // using this we can modify as we are modifying indirectly
	// but it generates a warning


	printf("%d\n",x);
	
	return 0;
}

