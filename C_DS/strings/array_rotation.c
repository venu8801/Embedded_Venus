
void rotate(int *arr, int s, int n);
//#define S 5
#include<stdio.h>
int main()
{
	int s;
	printf("Enter size: ");
	scanf("%d",&s);
	int arr[s];

	printf("Enter elements into array\n");
	int i,n;
	for(i = 0; i < s; i++)
	{
		printf("%d element: ",i);
		scanf("%d",&arr[i]);
	}	
	printf("Elements in array: ");
	for(i = 0; i < s; i++)
	{
		printf("%d ",arr[i]);
	}	
	
	printf("Enter no. of rotations: ");
	scanf("%d",&n);

		
	rotate(arr,s,n);
	printf("Elements in array: ");
	for(i = 0; i < s; i++)
	{
		printf("%d ",arr[i]);
	}	


}

void rotate(int *arr, int s, int n)
{
	int i, j;
	int temp;

	for(i = 0; i < n; i++)
	{
			temp = arr[0];
		for(j = 0; j < s-1; j++ )
		{
			arr[j] = arr[j+1];
		}
		arr[s-1] = temp;
	}
}
