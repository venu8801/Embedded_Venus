/* program to convert entire string into upper case*/

void str_Upper(char *str);
#include<stdio.h>
void main()
{
	char str[100];
	printf("enter the string: ");
	scanf("%[^\n]",str);


	str_Upper(str);
	printf("%s",str);

}

void str_Upper(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'z')
		{
			if(str[i] <= 'Z')
				str[i] += 32;
			else if(str[i] >= 'a')
				str[i] -= 32;
		}
	}
}

