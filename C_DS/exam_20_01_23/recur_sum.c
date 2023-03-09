/* program to find sum of digits of a number using recursion */
#include<stdio.h>
int sum_digits(int num)
{
	if(num == 0)
		return 0;
	int digit = num % 10;
	int sum = sum_digits(num/10);
	sum += digit;
	return sum;


}
void main()
{
	int num = 54;
	int sum = sum_digits(num);
	printf("sum: %d\n",sum);
}
