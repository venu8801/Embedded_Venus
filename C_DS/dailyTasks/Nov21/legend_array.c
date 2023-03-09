// program to print legend numbers in an array

void legend_num(int *ptr, int s);

void read_1d_arr(int *ptr, int s);

#define S 7
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int arr[S];
	printf("Enter elements into 1D array\n");
	read_1d_arr(arr,S);
	printf("\n-------------\n");
	
	legend_num(arr, S);
	printf("\n-------------\n");

}

void read_1d_arr(int *ptr, int s)
{	
	if(ptr == NULL)
	{
		printf("Null address recieved\n");
		exit(1);
	}
	int i;

	for(i = 0; i < s; i++)
		scanf("%d",&ptr[i]);
}


void legend_num(int *arr, int s)
{
	int i, j;
	int count;
	for(i = 0; i < s; i++)
	{
		count = 0;
		for(j = i+1; j < s; j++)
		{
			if(arr[i] > arr[j])
			{
				//printf("arr[i]:%d  %d\n",arr[i],arr[j]);
				count++;
			}
		}
		if(count == s-i-1)
			printf("%d ",arr[i]);

	}
}
