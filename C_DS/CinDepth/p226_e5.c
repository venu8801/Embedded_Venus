// page 226 example 6
#include<stdio.h>
int main()
{
	int i, arr[5] = {25,30,35,40,45}, *p;
	for(i = 0; i < 5; i++)
	{
		printf("%d ", *arr);
		arr++;
	}
	return 0;

}
