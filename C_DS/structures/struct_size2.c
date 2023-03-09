#include<stdio.h>
//#pragma pack(1)
struct st
{
	char y;
	char x;
	int n;
};

struct stm
{
	char y;
	char x;
	int n;
};

int main()
{
	printf("size of struct st is %d bytes\n",sizeof(struct st));
	printf("size of struct stm is %d bytes\n",sizeof(struct stm));
}
