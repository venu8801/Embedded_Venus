// using function pointer
void int_ascii(int num);
#include<stdio.h>
void main()
{
	
	int num;
	printf("Enter the num: ");
	scanf("%d",&num);

	int temp = num;
	int count = 0,rem,i;
	while(temp != 0)
	{
		temp = temp/10;
		count++;
	}
	printf("count: %d\n",count);
	temp = num;
	printf("temp:%d\n",temp);

	char arr[count];
	arr[count] = '\0';

	for(i = count - 1; i >= 0; i--)
	{	
		rem  = temp % 10;
		arr[i] = rem + 48;
		temp = temp / 10;
	}

	printf("the string: %s\n",arr);
}
