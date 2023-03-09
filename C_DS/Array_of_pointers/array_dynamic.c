
void display(char **dptr, int np);
void read(char **dptr, int np);
void** allocate(int np);
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int np, string_size;

	printf("Enter no. of pointers: ");
	scanf("%d",&np);

	char **dptr;

	dptr = (char **) allocate(np);

	read(dptr, np);


	display(dptr, np);

	return 0;

}

void** allocate(int np)
{
	void  **dptr;
	int i;

	dptr =  malloc(np * sizeof(char *));

	if(dptr == NULL)
	{
		printf("failed to allocate memory in heap\n");
		exit(1);
	}


	int str_size;

	printf("Enter size of string:");
	scanf("%d",&str_size);

	for(i = 0; i < np; i++)
	{
		dptr[i] = (char *) malloc( (str_size + 1) * sizeof(char) );

		if( dptr[i] == NULL)
		{
	
			printf("failed to allocate memory in heap\n");
			exit(1);
		}
	}
	return dptr;
}



void read(char **dptr, int np)
{
	int i;
	for(i = 0; i < np; i++)
	{
		
		printf("Address of char array:%p\n",dptr[i]);
		printf("Enter the string into character array:");
		scanf("%s",dptr[i]);
		printf("\n");
	}
	

}

void display(char **dptr, int np)
{
	int i;
	for(i = 0; i < np; i++)
	{	
		printf("Address of char array:%p\n",dptr[i]);
		printf("%s",dptr[i]);
		printf("\n");
	}
}
				
