/* program to count no. of words in a string*/
#include<stdio.h>
#include<string.h>
int count_words(char *str)
{
	if(str == NULL)
	{
		printf("Null received\n");
		return -1;
	}
	int i, count = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		if((str[i] == ' ') && (str[i+1] != ' ') )
			count++;
	}
	return count + 1;

}

void main()
{

	char str[100];
	printf("enter string:");
	scanf("%[^\n]",str);
	int count = count_words(str);
	printf("no. of words = %d\n",count);
}
