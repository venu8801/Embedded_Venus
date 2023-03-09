/*program to delete repeated characters in a string*/

void remove_repeated(char *str);
#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	printf("Enter the string:");
	scanf("%[^\n]",str);
	//printf("Entered string: %s\n",str);

	remove_repeated(str);
	printf("string:%s\n",str);

}
void remove_repeated(char *str)
{
	int i, j,k = 0,l;
	int count;
	for(i = 0; str[i] != '\0'; i++ )
	{	
		if(str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;

		//printf("str[i]: %c\n",str[i]);
		count = 0;
		if(str[i] == ' ')
			continue;
		for(j = i+1; str[j] != '\0'; j++)
		{	
			if(str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
			if(str[i] == str[j])
			{
				str[j] = ' ';
				count++;
				continue;

			}
			

		}
		if(count > 0)
		{
			str[i] = ' ';
			continue;
		}
		else
		{
			str[k] = str[i];
			k++;
		}
		
	}
	str[k] = '\0'; 

}

	

