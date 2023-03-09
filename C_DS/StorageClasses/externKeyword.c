/* program to understand extern keyword*/
/* when extern keyword is applied we are informing compiler that there is variable declared
 * some where outside you just perform operations on it even if it is not found in the current
 * scope*/

#include<stdio.h>
extern char  x;
extern int *ptr;
void main()
{
	printf("hello:%c\n",x);
	printf("y:%d\n",*ptr);
}

