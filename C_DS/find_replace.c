char* read_string(void);
int replace_string(char *str1, char *str2, char *str3);
void string_replace(char *str1, char *str2, char *str3);
int string_compare(char *str1, char *str2, int l2);
int search_string(char *str1, char *str2);
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count;
int main()
{
	char *str1; // pointer for main string
	printf("Main string: ");
	str1 = read_string();
	printf("Entered Main string: %s\n",str1);

	printf("String to searched: ");

	char *str2 = read_string();

	printf("Entered search string: %s\n",str1);
	char *str3;

	count = search_string(str1, str2);
	if(count >= 1)
	{
		printf("string is found %d times\n",count);
		printf("String to be replaced: ");

		str3 = read_string();
		string_replace(str1,str2,str3);
		printf("str size: %d\n",strlen(str1));
		printf("After replacing: %s\n",str1);
	}


	return 0;	
}
char* read_string()
{	
	char *str = NULL;
	int i =0, s = 1;
	while(1)
	{
		str = (char *)realloc(str,s * sizeof(char));
		if(str == NULL)
		{
			printf("-failed to allocate memory in heap\n");
			exit(0);
		}
		scanf("%c",&str[i]);
		if(str[i] == '\n')
			break;
		i++,s++;

	}
	str[i] ='\0';

	return str;
}

int search_string(char *str1, char *str2)
{
	int i;
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	int diff = l1 - l2;
	int ret, count = 0;
	for(i = 0; i <= diff;   )
	{

		ret = string_compare( &str1[i], str2, l2);
		if(ret == 0)
		{
			count++;
			i = i + l2;
		}

		else
			i++;
	}
	return count;
}
int string_compare(char *str1, char *str2, int l2)
{	
	//printf("entered string_compare\n");
	int i;

	for(i = 0; i < l2; i++)
	{
		if(str1[i] != str2[i])
			return -1;
	} 
	return 0;
}
void string_replace(char *str1, char *str2, char *str3)
{
	int l1 = strlen(str1);// main string
	int l2 = strlen(str2); // string to be searched
	int l3 = strlen(str3);// string to be replaced

	int diff;
	if(l2 != l3);
	{
		diff = l2 > l3 ? (l2-l3):(l3-l2);
		printf("diff:%d\n",diff);
		str1 = (char *)realloc(str1, (count * diff) * sizeof(char)  );
		if(str1 == NULL)
		{
			printf("#failed to allocate memory in heap\n");
			exit(0);
		}
	}
	replace_string(str1,str2,str3);

}
int replace_string(char *str1, char *str2, char *str3)
{
	int i,j,k,t;
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	int l3 = strlen(str3);
	int ret;
	int ind;
	int var = l2>l3 ?  (l2-l3):(l3-l2);
	for(i = 0; i <= l1-l2;   i++)
	{

		ret = string_compare( &str1[i], str2, l2);
		if(ret == 0)
		{

			if(l2 == l3)
			{
				j = 0;
				for(k  = i; k < l2; k++)
				{
					str1[k] = str3[j];
					j++;
				}
			}
			else if(l2 > l3)
			{
				for(k = 0; k < var; k++)
				{
					for(t = l2; t <= l1; t++)
					{
						str1[t] = str1[t+1];
					}
					l2--;
					ind = i;
					for(k  = 0; k < l3; k++,ind++)
					{
						str1[ind] = str3[k];
					}

				}
			}
			else
			{
				for(k = 0; k < var; k++)
				{
					for(t = l1; t >= i+l2; t-- )
					{
						str1[t+1] = str1[t];
					}
					//printf("str[k]:%c\n",str1[k]);
					l1++;
				}

				ind = i;
				for(k  = 0; k < l3; k++,ind++)
				{
					str1[ind] = str3[k];
					//printf("after replace str[k]:%c\n",str1[k]);

				}    
			}




		}


	}
	return count;
}









