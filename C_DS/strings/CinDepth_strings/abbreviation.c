/* program to convert given string into a abbreviation
 * example: World Health Organization --> WHO*/
#include<stdio.h>
void abbreviate(char *str1, char *str2)
{
	int i;
	int ind = 1;
	str2[0] = str1[0];
	for(i = 1; str1[i] != '\0'; i++)
	{
		if(str1[i] == ' ')
		{
			if( str1[i+1] >= 'A' && str1[i+1] <= 'Z'  )
			{
				str2[ind] = str1[i+1];
				ind++;
			}
		}

	}
	str2[ind] = '\0';
}
int main()
{
	char str1[30];
	char str2[10];
	printf("Enter the string: ");
	scanf("%[^\n]",str1);
	abbreviate(str1, str2);
	printf("short form: %s",str2);
	return 0;
}

