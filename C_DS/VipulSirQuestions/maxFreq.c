/* program to find highest frequency of a number in an array*/
#include<stdio.h>
int main()
{
	int arr[12] = {2,3,4,4,5,5,5,7,7,7,7,7};
	
	int i, j;
	int count, maxCount = 0, maxEle; 
	for(i = 0; i < 12; i++)
	{
		count = 1;
		for(j = i+1; j < 12; j++)
		{
			if(arr[i] == arr[j])
				count++;
		}
		if(count > maxCount)
		{	
			maxCount = count;
			maxEle = arr[i];
		}
		
		
	}
	printf("%d is element which occurs %d times\n",maxEle, maxCount);
}
