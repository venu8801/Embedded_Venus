int search_string(char *src, char *dst, int m, int n);
int string_compare(char *s1,char *s2,int n);
void search_replace(char *str1, char *dst, char *replace, char *out);
int string_copy(char *dst, char *src, int ind, int k);
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{

	int n, m, i,stack = 0,ret;
	char str1[1000];
	
	int diff;
			
	//printf("%p\n",str1); // starting address

	printf("Enter the string\n");

	scanf("%[^\n]s",str1);
	printf("old length: %d\n",strlen(str1));

	char dst[100];

	printf("Enter the string\n");
	scanf("%s",dst);


	n = strlen(dst); //length of string to be searched

	m = strlen(str1); 

	char replace[20];

	ret = search_string(str1, dst, m, n);
	printf("ret:%d\n",ret);
	
	
	if(ret >= 1)
	{
		char replace[100];
		printf("Enter string to be replaced: ");

		scanf("%s",replace);
		
		char out[1000];
		
		//printf("New length: %d\n",strlen(char));
		
		search_replace(str1,dst,replace,out);
		
		printf("%s\n",out);
		//str1[(m + strlen(replace))] = '\0';
			
		//printf("after replacing:\n %s\n",str1);
	}
	else
		printf("string not replaced:%s\n",str1);

}



int search_string(char *src, char *dst, int m, int n)
{
	
	int i,c = 0, stack = 0;

	for(i = 0; i <= (m-n); )
	{
		stack = string_compare(&src[i],dst,n);

		if(stack == 0)
		{
			c++;
			i = i + n;
		}
		else
		i++;
	}
	if(c >= 1)
	{
		printf("string is found\n");
		printf("count:%d\n",c);
	}
	else 
		printf("string not found\n");
	return c;	
}

int string_compare(char *s1,char *s2,int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(s1[i] != s2[i] )
			return 1;
	}
	return 0;
}



void search_replace(char *str1, char *dst, char *replace, char *out)
{
		int i,c = 0, stack = 0;
		int l = strlen(str1);
		int n = strlen(dst);
		int k = strlen(replace);
		int ind = 0; // index for out string
		int diff;
		if (k > n)
			diff = k - n;
		else 
			diff = n - k;
	for(i = 0; i <= (l-k); )
	{
		stack = string_compare(&str1[i],dst,n);
	
		if(stack == 0)
		{
			ind = string_copy(out, replace, ind, k);
			if(str1[i + l] == ' ' )
			{
				i = i + n;
				ind++;
				out[ind] = ' ';
			}
			else
			{
				i = i + n;	
			}
				
		}
		else
		{	
			if(i == (l-k))
			{
				string_copy(out, replace, ind+2, k);
				out[ind] = '\0';
			}
			
			ind = string_copy(out, &str1[i], ind ,1 );
			i++;
			printf("%s\n",out);
		}
	}
}
int string_copy(char *dst, char *src, int ind, int k)
{

	int i;
	for(i = 0; i < k ; i++)
	{
		dst[ind] = src[i];
		ind++;
	}
	return ind;
	

}
