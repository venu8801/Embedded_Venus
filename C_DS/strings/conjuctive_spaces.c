
void rm_conjuctiveSpaces(char *str);
#include<stdio.h>
#include<string.h>
int main()
{

	char input[100];


	printf("Enter the string:");
	scanf("%[^\n]",input);
	rm_conjuctiveSpaces(input);

	printf("%s\n",input);

}


void rm_conjuctiveSpaces(char *str)
{	
	int j = 0, i, k = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ' && str[i+1] == str[i])
		{
			continue;
		}

		else{
			str[k] = str[i];
			k++;
		}

 	}
	str[k] = '\0';	

}


