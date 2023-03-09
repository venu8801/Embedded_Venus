/* program to multiply two integers using only bitwise operators */
#include<stdio.h>
void main()
{
	int a , b;
	printf("enter a,b ")
	scanf("%d,%d",a,b );
	while(b > 0)
	{
		if(b & 1)
		{
			res = res + a;
		}
		a = a << 1;
		b = b >> 1;
	}
	printf("result: %d",res);


}
