/*program to find Multiplicative digital root and multiplicative persistence
 * example: num = 86 --> 8*6 = 48 --> 4*8 = 32 --> 3*2 = 6
 * MDR = 6 and Mpersistence = 3 as it took 3 times to reach single digit*/
/*C in depth:
 * chapter: functions
 * exercise:43
 */
#include<stdio.h>
int prodDigits(int num)
{
	int prod = 1;
	int digit;
	if(num > 0)
	{
		while(num > 0)
		{
			digit = num % 10;
			prod = prod*digit;
			num = num / 10;
		}
	}
	else
		return 0;
	return prod;
}
int MDR(int num)
{
	int temp = num;
	while(temp >= 10)
	{
		temp = prodDigits(temp);
	}
	return temp;
}
int Mpersistence(int num)
{
	int count = 0;
	while(num >= 10)
	{
		num = prodDigits(num);
		count++;
	}

	return count;
}
void main(void)
{
	int num;
	int prod;
	printf("Enter the number: ");
	scanf("%d",&num);
	printf("MDR = %d\n",MDR(num));
	printf("Mpersistence = %d\n",Mpersistence(num));


}

























