/* program to  decimal to binary using recursion */

int decimal_binary(int num);
#include<stdio.h>
int i = 1; // for power
int bin = 0;
void main()
{
	int num;
	printf("Enter the decimal number:");
	scanf("%d",&num);
	int ret = decimal_binary(num);
	printf("binary: %d\n",ret);

}
int decimal_binary(int num)
{	
	int  rem;
	if(num > 0)
	{
		rem = num % 2;
		bin = bin + rem*i;
	        printf("bin:%d\n",bin);	
		i = i * 10;
		decimal_binary(num/2);
	}
	return bin;
}

		 

		

