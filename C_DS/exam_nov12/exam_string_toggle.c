#include<stdio.h>
int toggle_string(char *str)
{
	int count = 0;
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{
		if( ((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a' ) && (str[i] <= 'z') ) )
		{
			if(str[i] <= 'Z')
			{
				count++;
				str[i] = str[i] + 32;
			}
			else
			{
				count++;
				str[i] = str[i] - 32;
			}

		}
		else if(str[i] == '%')
		{
			count++;
			str[i] = '&';
		}
		else if(str[i] == '(')
		{
			count++;
			str[i] = ')';
		}
		else if(str[i] == '*')
		{
			count++;
			str[i] = '+';
		}
	}
	return count;
}
void main()
{
	char arr[100];
	int count;
	printf("Enter the string:");
	scanf("%s",arr);
	count = toggle_string(arr);
	printf("no. of toggled letters: %d\n",count);
	printf("toggled output: %s\n",arr);
}	

