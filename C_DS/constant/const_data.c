#include<stdio.h>
int main()
{
	/*const keyword can be used in 3 ways 
	 * 1) for data  
	 * 2) for address
	 * 3) for data and address */

	int x = 10;

	int y =  20;

	const int *ptr;
	ptr = &x;
	printf("%d\n",ptr);

	//*ptr = 20; this generates compilation error 
	//as we are trying to modify data through address  and const keyword is 	applied to pointer variable 
	//
	//we can update data using its name but not its address 

	ptr = &y;
	printf("%d\n",ptr);
	return 0;

}
	
