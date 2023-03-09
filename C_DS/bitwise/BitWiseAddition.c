// program to add two numbers using bitwise operations
#include<stdio.h>
int main()
{
	unsigned int a = 55;
	unsigned int b = 8;
	unsigned int carry, sum;
	while(b != 0)
	{
		sum = a ^ b;
		carry = a & b;

		b  = carry << 1;
	}
	printf("answer: %d", sum);
}
