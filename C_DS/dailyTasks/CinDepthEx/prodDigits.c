/* program to find the product of all digits of a number*/
/*C in depth:
 * chapter: functions
 * exercise:42
 */
int prodDigits(int );
#include<stdio.h>
void main(void)
{
	int num;
	int prod;
	printf("Enter the number: ");
	scanf("%d",&num);
	prod = prodDigits(num);
	printf("Product of digits = %d\n",prod);

}
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






