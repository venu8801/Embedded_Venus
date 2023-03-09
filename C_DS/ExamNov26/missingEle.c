int findMissing(int *arr, int n);
#include<stdio.h>
void main()
{
	int arr[13] = {2,3,4,5,6,7,8,9,11,12,13,14,15};
	printf("missing element: %d\n",findMissing(arr, 13));
}
int findMissing(int *arr, int n)
{
	int i,max = 0;
	int sum = 0, arrsum = 0;
	for(i = 0; i < n; i++)
	{
		if(arr[i] > max)
			max = arr[i];
		arrsum += arr[i];

	}
	printf("max:%d\n",max);
	int min = max;
	for(i = 0; i < n; i++)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	printf("min:%d\n",min);
	for(i = min; i <= max; i++)
	{
		sum += i;
	}
	
	return sum - arrsum;
}
