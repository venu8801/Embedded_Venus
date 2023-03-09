
int search_delete(char *str, char ch, char *ptr);
#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
void main()
{
	char str[1000]; // main string
	char ch; // character to be deleted
	char ptr[1000];// output string



	printf("Enter the string:");
	scanf("%[^\n]",str);

	
	__fpurge(stdin);
	printf("Enter the character to be deleted:");
	scanf("%c",&ch);


	int c = search_delete(str, ch,ptr);
	if(c >= 1)
		printf("string after deleting: %s\n",ptr);
	else
		printf("Character not found\n");

}

int search_delete(char *str, char ch, char *ptr)
{		// main string // char  // new string

	int i,j,c = 0;
	

	for(i = 0,j = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ch)
		{
			c++;
			continue;
		}
		ptr[j] = str[i];
		j++;

		
	}
	printf("----------\n");
	return c;
/*	for(i = 0, j = 0; str[i] != '\0'; i++)
	{
		if(str[i] == '#')
			continue;
			
		ptr[j] = str[i];
		j++;
	}
	ptr[j] = '\0';
*/
}


