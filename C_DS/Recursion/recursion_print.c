
/* printing numbers from 1 to 10 using recursion*/

void recursive_print(int num);
#include<stdio.h>
int main()
{
	int num = 1;
	recursive_print(num);

}

void recursive_print(int num)
{
	if(num > 10)
		return;
	printf("num: %d\n",num);
	num++;
	recursive_print(num);
}

