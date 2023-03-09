//program to find the largest string and a smallest string in a given string

void Big_StrFinder(char *str);
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter the string: ");
	scanf("%[^\n]",str);
	printf("Entered String: %s\n",str);

	Big_StrFinder(str);



}

void Big_StrFinder(char *str)
{
	int maxDiff = 0, maxStart = 0, maxEnd = 0;
	int i, diff = 0;
	int start = 0, end = 0;
	char large[50];
	int n = strlen(str);
	for(i = 0; str[i] != '\0'; i++)
	{
		//printf("%c ",str[i]);
		if( (str[i] == ' ') || (str[i+1] == 0))
		{	
			if(str[i+1] == 0)
				end++;
			//printf("end: %d\n",end);
			diff = end - start;
			//printf("diff: %d\n",diff);
			
			
			
			if(diff > maxDiff) //if the diff is bigger than maxDiff then update maxDiff and start and end pos of word
			{
				maxDiff = diff;
				maxStart = start;
				maxEnd = end;
			}
			start = i + 1;

		}
		end++;
	}
	//printf(" maxDiff: %d",maxDiff);
	char maxWord[25];
	int j = 0;
	for(i = maxStart; i < maxEnd;  i++, j++)
	{
		maxWord[j] = str[i];
	}
	maxWord[j] = '\0';
	printf("Largest Word: %s\n",maxWord);
}
	
/*void Small_Str_Finder(char *str)
{
	char small[100];
	strcpy(small, str);
	int minCount = strlen(str);
	int minStart, minEnd;
	int start = 0, end = 0;
	int i;
	for(i */	
	
