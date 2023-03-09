int str_sort_comp(char *,char *);
int str_comp(char *str1, char *str2);
void search(char **, int, char*);
char* input(char **ptr);
void print(char **dptr,int len);
#include<stdio_ext.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char *ptr[10]; // array of pointers
	printf("array of pointers address: %p\n",ptr);
	char in[100]; // input stirng for search function
	char option;
	int i = 0;
	int ret = 9, j = 0 , k = 0;
	char *TemPtr;
	while(1)
	{
		printf("Select an option\n");
		printf("a.input\nb.print\nc.sort\nd.search\ne.quit\n");
		__fpurge(stdin);
		scanf("%c",&option);


		switch(option)
		{
			case 'e':
				printf("you have selected option %c\n",option);
				exit(0);
			case 'a':
				printf("you have selected option %c\n",option);
				printf("Enter the string:");
				ptr[i] = input(ptr);
				printf("stored in array: %p\n",ptr[i]);	
				i++;
				break;
			case 'b':
				printf("you have selected option %c\n",option);
				printf("printing all strings \n");
				print(ptr, i);
				break;
			case 'c':
				printf("sorting strings in list of strings\n");
				for(k = 0; k < i; k++)
				{
					for(j = 0; j < i; j++)
					{
						//printf("str1: %p and str2: %p\n",ptr[k],ptr[j]);
						ret = str_sort_comp(ptr[k],ptr[j]);
						printf("ret:%d",ret);
						if(ret > 0)
						{
							TemPtr = ptr[k];
							ptr[k] = ptr[j];
							ptr[j] = TemPtr;
						}
					}
				}
				break;


			case 'd':
				printf("you have selected option %c\n",option);
				printf("Enter the string to be searched:");
				__fpurge(stdin);
				scanf("%[^\n]",in);
				search(ptr, i, in);
				break;
			default:
				printf("you have selected invalid option\n");
				printf("quitting--");
				exit(-1);
		}


	}
}
char* input(char **ptr)
{
	printf("sorting strings in list of strings\n");
	char *p = (char *)malloc(1*sizeof(char));
	int i = 0;
	int j = 1;
	char ch;
	__fpurge(stdin);
	while(ch != '\n')
	{
		ch = getc(stdin);
		p = (char *)realloc( p, j*sizeof(char) );
		p[i] = ch;
		i++,j++;
	}
	p[i-1] = '\0';
	printf("%s",p);
	printf("Recived array of pointers address: %p\n",ptr);
	printf("string base address in heap: %p\n",p);
	return p;
}
void print(char **dptr,int len)
{
	int i;

	for(i = 0; i < len; i++)
	{

		printf("%s\n",*(dptr + i));
		//printf("dptr[i]: %p\n",&*(dptr+i));
	}
}
void search(char **dptr, int len, char *input)
{
	int i, count = 0, ret = 0;
	for(i = 0; i < len; i++)
	{

		//printf("entered loop\n");
		ret = str_comp(dptr[i], input);
		//printf("ret:%d\n",ret);
		if(ret == 0)
			count++;
		else
			continue;


	}
	if(count > 0)
	{
		printf("String found: %d times\n",count);
		return;
	}
	return;
}

int str_comp(char *str1, char *str2)
{	
	//printf("str1: %s and str2: %s\n",str1,str2);
	int i;
	for(i = 0;( str1[i]!= '\0' || str2[i]!= '\0' ); i++)
	{
		if(str1[i] != str2[i])
			return -1;
	}
	return 0;
}
int str_sort_comp(char *str1, char *str2)
{
	printf("entered sort func\n");
	printf("str1: %s and str2: %s\n",str1,str2);
	int i;

	for(i = 0; (str1[i]!='\0' || str2[i]!='\0'); i++)
	{
		if(str1[i] < str2[i])
			return 1;
		else if(str1[i]>str2[i])
			return -1;

	}
	return 0;
}

















