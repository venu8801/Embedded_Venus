/*program to convert given string in float to actual float value*/
float ascii_float(char*);
#include<stdio.h>
void main()
{
	int i = 1;

	char input[15];

	printf("Enter the numeric string: ");
	scanf("%s",input);
	float num = ascii_float(input);
	printf("num: %f\n",num);
}
float ascii_float(char *str)
{
	int i;
	int m = 1;
	int num;
	int sum = 0;
	int dsum = 0, dnum;
	for(i = 0; str[i] != '.'; i++)
	{
	/*	num = str[i]-48;
		printf("%d\n",num);
		sum = sum + num * m;
		m = m*10; // this logic reverses number
	*/
		num = str[i]-48;
		sum = sum * 10 + num;
	}
	for(i++; str[i] != '\0'; i++)
	{
		
		dnum = str[i]-48;
		dsum = dsum * 10 + dnum;
		m *= 10;
	}
	//printf("dsum:%d\n",dsum);
	float out  = sum + (float)dsum/(float) m;
	//printf("f:%f\n",f);

 
	return out;
}
