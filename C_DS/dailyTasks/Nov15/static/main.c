#include<stdio.h>
#include "venus.h"
void main()
{
	int num, ret;
	printf("enter the number:");
	scanf("%d",&num);
	ret = reverse(num); 
       printf("reverse of given num: %d\n",ret);
}


