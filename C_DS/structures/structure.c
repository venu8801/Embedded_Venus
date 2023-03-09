struct employee
{
	char name[30];
	int id;
	char gender;
};
#include<stdio.h>
void main()
{	
	struct employee e1 = {"venu", 422, 'M'};
	printf("size of struct: %d\n",sizeof(struct employee));
	printf("address: %p    name: %s\n",&e1.name,e1.name);
	printf("id: %d\n",e1.id);
	printf("address: %p\n",&e1.id);
	printf("gender: %c\n",e1.gender);
	printf("address: %p\n",&e1.gender);


}


