/* program to find the next biggest element to the first element in an array*/
#include<stdio.h>
#include<limits.h>
void main()
{
	int arr[6] = {9,1,2,11,9,12};
	
	int i, prev_big = INT_MAX, nextBig = 0;
	int big = INT_MAX;
	int f_ele = arr[0];
	for(i=1; i < 6; i++)
	{	
		
		if(f_ele < arr[i])
		{
			big = arr[i];
			if(arr[i] < prev_big)
			{
				nextBig = arr[i];
				prev_big = big;
			}
		}
		
		

	}
	printf("next biggest: %d\n",nextBig);
}
