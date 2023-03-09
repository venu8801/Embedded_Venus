
int findMax(int *arr, int n);
	
void display(int *arr,int len);
void read(int *arr,int len);
#include<stdio.h>
#include<stdio_ext.h>
int max  = 0;
int j = 0;
void main()
{
	int n;
	printf("Enter no. of elements");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements\n");
	
	read(arr,n);
	display(arr,n);
	int max = findMax(arr, n);
	printf("Max element: %d\n",max);


}
void read(int *arr,int len)
{
	int i;
	for(i = 0; i < len; i++)
	{	
		//__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
}
void display(int *arr,int len)
{       
        int i;
        for(i = 0; i < len; i++)
        {       
                printf("%d ",arr[i]);
        } 
  printf("\n");	
} 
int findMax(int *arr, int n)
{
	if(j == n)
		return max;
	if( arr[j] > max)
	{
		max = arr[j];
		
	}
	j++;
	findMax(arr, n);
	return max;
}

		

