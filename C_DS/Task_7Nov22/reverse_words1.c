

void reverse_words(char *str, char *ptr);
void word_write(char *ptr, char *word, int k);
void word_reverse(char *word);
#include<string.h>

#include<stdio.h>
void main()
{
	char str[1000];  // input string
	char dst[1000];  // output string
	printf("Enter the string: ");
	scanf("%[^\n]",str);

	reverse_words(str,dst);

	printf("%s\n",dst);



}


void reverse_words(char *str, char *ptr)
{
	char word[1000];
	int i,k = 0,j = 0;
	int n = strlen(str);
	for(i = 0; str[i] != '\0'; i++)
	{	
		
		if(str[i] != ' ' || i == n)
		{	//printf("%d\n",n);
			//printf("%c\n",str[i]);
			word[j++] = str[i];
			//printf("%c\n",word[j]);
			//j++;
			if(i + 1 == n)
			{
				printf("j = %d\n",j);
				word[j] = '\0';
			printf("%s\n",word);
			}

		}
		else
		{
				printf("j = %d\n",j);

			word[j] = '\0';
	
		
		
	
		
			printf("%s\n",word);
			//word_reverse(word); // calling reverse function;	
			
			/*word_write(ptr, word,k);
			k++;
			ptr[k] = '\0';*/
			j = 0;
		}


	}



}
void word_reverse(char *word)
{	
	
	int len = strlen(word);
	int k , j;
	char temp;

	for(k = 0; k < len/2 ; k++)
	{
		if(word[k] != word[len - k - 1])
		{
			temp = word[k];
			word[k] = word[len - k - 1];
			word[len - k - 1] = temp;
		
		}
				
	}
	//printf("%s\n",word);

}



void word_write(char *ptr, char *word, int k)
{
	int i;
	int l = strlen(word);
	for(i = 0; i < l; i++)
	{
		ptr[k] = word[i];

	}




}















