#include<stdio.h>
int main()
{
	int x[5] = {10,20,30,40,50};

	int *ptr = x;

	int ret;

	ret = (int *)&ptr[2] - (int *)&ptr[0];

	printf("%d \n",ret);
	ret = (void *)&ptr[2] - (void *)&ptr[0];
	printf("%d \n",ret);






	return 0;
}

