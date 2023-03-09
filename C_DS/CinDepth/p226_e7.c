// p226 e7
#include<stdio.h>
int main()
{
	int i, arr[5] = {25,3035,40,45}, *p = arr;

	for(i = 0; i < 5; i++)
	{
		(*p)++;
		printf("%d ",*p);
		p++;
	}
	return 0;
}
