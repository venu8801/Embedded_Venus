//program to find a sub-string and replace it with other string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Str_Compare(char *str1, char *str2, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		if(str1[i] != str2[i])
			return -1;
	}
	return 0;
}

void strCpy(char *s1, char *s2, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		s1[i] = s2[i];

	}

}
void strCppy(char *s1, char *s2)
{
	int i;

	for(i = 0; s2[i] != '\0'; i++)
	{
		s1[i] = s2[i];

	}
	s1[i] = '\0';
	

}
void Search_Replace(char *mStr, char *sStr, char *rStr )
{
	int ml , ssl, rl;

	ml = strlen(mStr);

	ssl = strlen(sStr);

	rl = strlen(rStr);

	char *ptr; 

	int overall = ssl - rl;
	if(overall < 0)
		overall = -(overall);
	int diff = ml - ssl;
	int i, ret;
	int newSize = ml;
	char buff[1000];
	for(i = 0; 1;)
	{
		if(mStr[i] == 0)
			break;
		ret = Str_Compare(&mStr[i], sStr, ssl);
		printf("ret:%d\n",ret);
		if(ret == 0)
		{	
			newSize += overall;
			printf("new size:%d\n",newSize);

			ptr = (char *)realloc( mStr, (newSize) * sizeof(char) );
			if(ptr == NULL)
			{
				printf("Failed to allocate memory in heap\n");
				exit(3);
			}
			
			//printf("%c\n",mStr[i+ssl+1]);
			printf("i+ssl:%d",i+ssl);
			strcpy(buff, &mStr[i+ssl]);
			printf("%s",buff);
			strcpy(&mStr[i + rl], buff);
			strCpy(&mStr[i], rStr, rl);
			i = i+ssl;
			
					

		}
		else
			i++;
				
	

	}


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
			printf("failed to allocate memory in heap\n");
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


void main()
{

	char *mStr;
	char sStr[50];

	char rStr[100];

	printf("Enter main string: ");
//		scanf("%s",mStr);
	mStr = read_string();

	printf("Enter Search String: ");
	scanf("%s",sStr);
	__fpurge(stdin);
	//
	printf("Enter replace string: ");
	scanf("%s",rStr);

	printf("main string: %s \n",mStr);
	printf("Search string: %s \n",sStr);
	printf("replace string: %s \n",rStr);

	Search_Replace(mStr, sStr, rStr);

	printf("After replacing: %s",mStr);


}
