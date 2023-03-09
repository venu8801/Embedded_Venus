
void vowel_count(char *arr);


#include<stdio.h>
void main()
{
	char str[1000];

	printf("Enter the string: ");

	scanf("%[^\n]",str);
	vowel_count(str);
}



void vowel_count(char *arr)
{
	char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','\0'};

	int i = 0,j = 0;
	int total = 0, count = 0;
	for(i =0; vowels[i] != '\0'; i++)
	{	
		count = 0;

		for(j = 0; arr[j] != '\0'; j++)
		{	
			if(vowels[i] == arr[j])
			{
				count++;
				total++;
			}
		}

		if(count >= 1)
		{
				printf("vowel:%c----count:%d\n",vowels[i],count);
		}
			
	}
	printf("Total count: %d\n",total);	

}
