//----@copyrighted to surya------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 32
#define SIZE 10
struct student
{
	unsigned char age;
	char gender;
	char name[MAX_NAME];
};


struct student *ptr[SIZE];

void init_hash_table()
{

	int i;
	for(i = 0; i < SIZE; i++)
	{
		ptr[i] = NULL;


	}


}

int hash_student(char *name)
{

	if(name == NULL) return -1;
	return name[0] % SIZE;


}

int insert_hash(struct student s)
{
	int key = hash_student(s.name);
	
	if((key < 0)&&(key>9))
		return -1;

	struct student * cptr = (struct student *)malloc(1 * sizeof(struct student));
	if(cptr == NULL)
	{
		printf("failed to create memry\n");
		exit(1);
	}

	strcpy(cptr->name, s.name);

	cptr->gender = s.gender;

	cptr->age = s.age;


	if(ptr[key] == NULL)
	{
		ptr[key] = cptr;
		return 0;
	}

	else
		return -1;


}

void  search_hash(char *name)
{
	int key = hash_student(name);
	if(ptr[key]  != NULL)
	{
		printf("name: %s\n", ptr[key]->name);
		printf("age: %d\n",ptr[key]->age);
		printf("gender: %c\n",ptr[key]->gender);
	}		
	else
		printf("key not found\n");

}


void main()
{


	struct student s1 = {.name = "surya", .gender = 'M', .age = 25};
	struct student s2 = {.name = "pranav", .gender = 'M', .age = 25};
	struct student s3 = {.name = "venu", .gender = 'M', .age = 25};
	struct student s4 = {.name = "dharmi", .gender = 'M', .age = 25};


	init_hash_table();

	insert_hash(s1);
	insert_hash(s2);
	insert_hash(s3);
	insert_hash(s4);
	
	
	int key = 0;
	for(key = 0; key < SIZE; key++)
	{
		if(ptr[key] != NULL)
		{
			printf("key : %d\n", key);
			printf("name: %s\n", ptr[key]->name);
			printf("age: %d\n",ptr[key]->age);
			printf("gender: %c\n",ptr[key]->gender);
		}


	}

	printf("-----search---------\n");
	search_hash("surya");
	printf("-----search---------\n");
	search_hash("dali");






}













