/* program to find max and min element in array*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void main()
{
	int max = INT_MIN, min = INT_MAX;

	int arr[10] = {2,5,-1,5,44,3,-7,3,52,0};

	int i;
	for(i = 0; i < 10; i++)
	{
		if(arr[i] < min)
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	printf("max: %d\n",max);
	printf("min: %d\n",min);
}
