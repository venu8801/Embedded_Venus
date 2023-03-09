
void str_descend(char *str);
	
#include<stdio.h>
void main()
{
	char str[50] = "hello";

	//str_descend(arr);

	printf("before descending: %s\n",str);

	int i, j;
//	int len = strlen(str);
	char temp;
	for(i = 0; str[i] != '\0'; i++)
	{
		for(j = i + 1 ; str[j] != '\0'; j++)
		{
			if(str[i] < str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	printf("after descending: %s\n",str);
}	
