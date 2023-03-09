// program to find whether a given number is a perfect number or not

int perfect(int num);
#include<stdio.h>
void main()
{
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	int ret = perfect(num);
	if(ret == 1)
		printf("\nIt is a perfect number\n");
	else
		printf("\nNot a perfect number\n");


}

int perfect(int num)
{
	int i, j = 0;
	int sum = 0;
	int size = 0;
	for(i = 1; i < num; i++) // to find no. of factors
		if(num % i == 0)
			size++;
	printf("s:%d\n",size);
	int arr[size];
	for(i = 1; i < num - 1; i++ )
	{
		if(num % i == 0)
		{
			//printf("i:%d\n",i);
			arr[j] = i;
			j++;
		}
	}
	printf("factors: ");
	for(i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	
		sum += arr[i];
	}
	if(sum == num)
		return 1;
	return 0;
}

	
