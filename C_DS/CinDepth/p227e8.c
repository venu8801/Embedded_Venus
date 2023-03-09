#include<stdio.h>
int main()
{
	int i, arr[5] = {25,40,55,70,85}, *p = arr;
	for(i = 0; i < 5; i++)
		printf("%d ", *p++);  // this is equivalent to *(p++) but this is post fix increment 
	// so value gets submitted first and gets dereferenced first, later it is incremented
	printf("\n");
	for(i = 0; i < 5; i++)
		printf("%d ", *--p);
	printf("\n");
	return 0;
}

