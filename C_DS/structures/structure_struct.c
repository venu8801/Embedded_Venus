/* assignment on structures Nov 29*/
struct dob
  {
  int dd;
  int mm;
  int yy;
  };
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

struct employee
{
	char name[32];
	int id;
	char gender;
	float salary;
	struct dob dt;
};

void read(struct employee*, int);
void display(struct employee*, int);
void de_alloc(struct employee*);
struct employee* allocate(struct employee *);
void swap(struct employee *, int);

struct fpointers
{
	void(*fread)(struct employee *, int );
	void(*fdisplay)(struct employee *, int);
	void(*fswap)(struct employee *, int);
	struct employee* (*fallocate)(struct employee*);
	void(*fde_alloc)(struct employee *);
};


int   alc;
int ind = 0;
	int size = 0;
void main()
{
	struct employee *ptr = NULL;
	char opt;

	struct fpointers fp = {read, display, swap, allocate, de_alloc};

	while(1)
	{
		printf("---------------------\n");
		printf("Select an option: \n");
		printf("a.allocate\nb.read\nc.display\nd.swap\ne.de-allocate\nf.exit\n");
		__fpurge(stdin);
		scanf("%c",&opt);
		switch(opt)
		{
			case 'a':
				printf("-------allocating-------\n");
				ptr = fp.fallocate(ptr);
				printf("allocation complete\n");
				size++;
				break;

			case 'b':
				printf("--------read-----------\n");
				if(alc <= 0)
					printf("please allocate\n");
				else if(ind == alc)
					printf("Already read please allocate\n");
				else if(ind < alc)
				{
					fp.fread(ptr, size);
				}
				break;
			case 'c':
				printf("----------display--------\n");
				if(size <= 0)
					printf("Array contains no structures\n");
				else
					fp.fdisplay(ptr, size);
				break;
			case 'd':
				printf("--------swap----------\n");
				if(ptr == NULL || size == 0)
					printf("array is empty cannot perform swap\n");
				else
				{
					fp.fswap(ptr, size);
					printf("swapping complete\n");
				}
				break;
			case 'e':
				printf("address before: %p\n",ptr);
				if(ptr == NULL)
					printf("ptr contains NULL cannot de-allocate\n");

				
				else
				{
					printf("-------de-allocating---------\n");
					fp.fde_alloc(ptr);
					printf("de-allocation complete\n");
					printf("all values are reset to their defaults\n");
				}
				break;
			case 'f':
				printf("---------exit---------\n");
				exit(0);
				break;
			default:
				printf("Invalid option selected\n");
				printf("--->quitting\n");
				exit(0);
		}

	}






}
















struct employee* allocate(struct employee *ptr)
{
	alc++;
	
	ptr = (struct employee*)realloc(ptr, alc * sizeof(struct employee) );
	if(ptr == NULL)
	{
		printf("failed to allocate memory\n");
		exit(0);
	}
	return ptr;
}


void read(struct employee *ptr, int n)
{
	int i;
	printf("Enter the data of employee %d \n",ind+1);
	for(i = ind; i < n; i++)
	{
		printf("Enter the employee name: ");
		__fpurge(stdin);
		scanf("%[^\n]", ptr[i].name);
		printf("Enter employee id no.: ");
		__fpurge(stdin);
		scanf("%d",&ptr[i].id);
		printf("Enter employee gender: ");
		__fpurge(stdin);
		scanf("%c",&ptr[i].gender);

		printf("Enter employee salary: ");
		__fpurge(stdin);
		scanf("%f",&ptr[i].salary);
		
		printf("Enter the employee DOB dd/mm/yy: ");
		__fpurge(stdin);
		scanf("%2d/%2d/%4d",&ptr[i].dt.dd,&ptr[i].dt.mm,&ptr[i].dt.yy );
	}
	ind++;	
}
void display(struct employee *ptr, int n)
{       
	int i;
	printf("size of array: %d\n",n);
	for(i = 0; i < n; i++)
	{
		printf("Struct BaseAddress: %p\n",&ptr[i]);
		printf("--------\n");
		printf("Employee name: %s\n", ptr[i].name);
		printf("Employee id no.: %d\n",ptr[i].id);
		printf("Employee gender: %c\n",ptr[i].gender);
		printf("Employee salary: %.3f\n",ptr[i].salary);
	
		printf("Employee DOB dd/mm/yy: ");
		
		printf("%d/%d/%d\n",ptr[i].dt.dd,ptr[i].dt.mm,ptr[i].dt.yy );
	}
	printf("-------------------\n");
}
void de_alloc(struct employee *ptr)
{	
	


		free(ptr);
		ptr = NULL;
		ind = 0;
		alc = 0;
		size = 0;

	//resetting all values
}

void swap(struct employee *ptr, int n)
{
	int i;
	struct employee temp;
	for(i = 0; i < n/2; i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[n-i-1];
		ptr[n-i-1] = temp;
		
	}
	
}
	
		
	





