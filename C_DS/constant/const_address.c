#include<stdio.h>
int main()
{
	/*const to address in this type constant keyword is applied to address 
	 * instead of data so this wont allow changes to adresses but allows
	 * changes of data*/

	int x = 10;
	int y = 15;
	int * const ptr = &x;  // pointer variable applied with constant keyword
	// it must be defined with a valid address while declaring or else 
	// we cannot declare it later as const keyword doesnt allow us 
	// to modify or update 
	

	//ptr = &y // this will give a compilation error as we are trying to
	//modify ptr variable

	*ptr = 29;

	printf("%p\n",ptr);

	printf("%d\n",x);

	return 0;
}
