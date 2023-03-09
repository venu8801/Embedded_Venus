/* decimal to binary using bitwise operators*/

void bin_decimal(int num);
#include<stdio.h>
int i = 31;
int main()
{
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	bin_decimal(num);
	
}
void bin_decimal(int num)
{
	if(i >= 0)
	{
		if( (num & (0x1 << i)) == 0)
			printf("0");
		else
			printf("1");
		i--;
		bin_decimal(num);
	}
	return;
}
