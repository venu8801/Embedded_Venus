#include<stdio.h>
void main()
{
	float x =  3.14;

	int i;
	int *ptr = &x;
	for(i = 31; i>=0; i-- )
	{
	//	printf("%d",(*ptr>>i)&1);
		if( ((*ptr >> i) &1 ) == 0 )
		//if( (*ptr&(0x1 << i)) ==  0)
			printf("0");
		else
			printf("1");
	}
}

