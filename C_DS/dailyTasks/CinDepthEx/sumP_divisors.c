/*program to find sum of proper divisors*/
/*C in depth:
 * chapter: functions
 * exercise:44
 */
int sumPdivisors(int);
#include<stdio.h>
void main(void)
{
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	int sum = sumPdivisors(num);
	printf("sum of all divisors: %d\n",sum);

}
int sumPdivisors(int num)
{
	int i;
	int sum = 0;
	for(i = 1; i < num; i++)
	{
		if(num % i == 0)
		{
			printf("i = %d\n",i);
			sum += i;
		}
	}
	return sum;
}

