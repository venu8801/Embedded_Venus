/* string reversal function using recursive function*/

void str_reverse(char *str, int i, int l);
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter the string:");
	scanf("%[^\n]",str);
	int i = 0;
	int len = strlen(str);
	str_reverse(str, i, len);

	printf("reversed string: %s\n",str);

}

void str_reverse(char *str, int i, int l)
{	
	char temp;
	
	if(i == l/2)  // condition for termination of string reversal function
		return;
	temp = str[i];
	str[i] = str[l-i-1];
	str[l-i-1] = temp;
	i++;
	str_reverse(str, i, l);
	


	


}

