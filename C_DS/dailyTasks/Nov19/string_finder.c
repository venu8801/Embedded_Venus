#include<stdio.h>
void string_find(char *str);
void main()
{
	char arr[1000];
	printf("Enter the string: ");
	scanf("%[^\n]",arr);
	string_find(arr);


}


void string_find(char *str)
{
	int i,j,k,z,max = 0,max1 = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		printf("str[i]:%c\n",str[i]);
		for(j = i+1; str[j] != '\0'; j++)
		{
			if(str[i] == str[j])
			{
		printf("str[i]:%c\n",str[i]);
				max = (j-i)-1;
			//	i = j;
				k = j;
				for(k; str[k] != '\0'; k++)
				{
					if(str[k] == str[j])
					{
						max1 = (k-j)-1;
						if(max1 > max)
						{
							z = j;
							for(z; z <= k;z++)
							{
								printf("%c",str[z]);
							}
						}
					}
				}
			}
		}
	}
}

								
