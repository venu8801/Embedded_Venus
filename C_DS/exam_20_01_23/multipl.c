#include<stdio.h>
void mul(int *a, int *b, int *c)
{
	*c = (*a) * (*b);
}
void main()
{
	int a, b, c;


	a = 3, b = 4;

	mul(&a, &b, &c);
	printf("c = %d\n",c);	

}

