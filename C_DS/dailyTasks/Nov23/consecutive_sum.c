/*program to find  consecutive numbers whose sum is equal to given number*/
#include<stdio.h>
void main()
{
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	int i,j,k;
	int sum;
	int flag = 0;
	int count = 0;
	for(i = 1; i < num; i++)
	{
		sum = 0;
		flag = 0;
		for(j = i; j < num; j++)
		{
			sum += j;
			if(num == sum)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			count++;
			for(k = i; k <= j; k++)
			{
				if(k < j)
					printf("%d + ",k);
				else
					printf("%d",k );
			}
			//printf("\b\b");
			//printf("  ");
			printf("\n");
			continue;
		}
	}
	printf("num: %d can be represented in %d ways\n",num,count);
}
