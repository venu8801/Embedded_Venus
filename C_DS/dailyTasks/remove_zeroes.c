
void zeroSider(int *arr, int s);
#include<stdio.h>
int main()
{
	int s;
	printf("Enter the size of arr:" );
	scanf("%d",&s);
	int arr[s],i;
	for(i = 0; i < s; i++ )
	{
		scanf("%d",&arr[i]);

	}
	printf("Array elements: ");
	for(i = 0; i < s; i++ )
	{
		printf("%d ",arr[i]);
	}

	printf("\n");

	zeroSider(arr, s);
	printf("Array elements: ");

	for(i = 0; i < s; i++ )
	{
		//printf("entered");
		printf("%d ",arr[i]);
	}


}

void zeroSider(int *arr, int s)
{
	int i, j,count = 0;
	for(i = 0; i < s; i++)
	{	
	//	printf("%d\n",arr[i]);
		if(arr[i] == 0)
		{
			printf("i:%d\n",i);
			for(j = i; j < s; j++)
			{
				arr[j] = arr[j+1];
			}
			count++;
			i--;
			
		}

	}
	//int Size = s;
	printf("cnt: %d\n",count);
	for(j = 0 ; j < count ; j++ )
	{
		arr[i-1] = 0;
		i--;
	}
}


























