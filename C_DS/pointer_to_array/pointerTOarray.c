/* pointer to an array
 * array of pointers is different from pointer to array 
 * pointer to array contains a address which points to an array
 * when incremented this address jumps total size of the array */
#include<stdio.h>
void main()
{	
	int arr[5];
	int (*ptr)[5] = arr;
	int i;

	arr[0] = 6;
	arr[1] = 16;
	arr[2] = 26;
	arr[3] = 36;

	for(i = 0; i < 4; i++)
	{
		printf("%d ",arr[i]);
	}
}	
