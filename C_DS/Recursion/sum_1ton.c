/* program to print sum of numbers from 1 to n using recursion*/

int sum_of_n(int num);
#include<stdio.h>
int main()
{
	int num;
	printf("Enter the value of num: ");
	scanf("%d",&num);

	int sum = sum_of_n(num);
	printf("sum: %d\n",sum);

}

int sum_of_n(int num)
{
	int sum;

	if(num == 0)
		return 0;
	sum = num + sum_of_n(num - 1);
	return sum;
}

